#pragma once

#include <set>
#include <functional>
#include <unordered_set>
#include <vector>

/*
Шаблонный интерфейс IObserver. Его должен реализовывать класс, 
желающий получать уведомления от соответствующего IObservable
Параметром шаблона является тип аргумента,
передаваемого Наблюдателю в метод Update
*/

template <typename T>
class IObserver
{
public:
	virtual void Update(T const& data) = 0;
	virtual ~IObserver() = default;
};

/*
Шаблонный интерфейс IObservable. Позволяет подписаться и отписаться на оповещения, а также
инициировать рассылку уведомлений зарегистрированным наблюдателям.
*/
template <typename T>
class IObservable
{
public:
	virtual ~IObservable() = default;
	virtual void RegisterObserver(IObserver<T> & observer, uint32_t priority = 5) = 0;
	virtual void NotifyObservers() = 0;
	virtual void RemoveObserver(IObserver<T>& observer) = 0;
};

// Реализация интерфейса IObservable
template <class T>
class CObservable : public IObservable<T>
{
public:
	CObservable() {
		m_observers.resize(5);
	}

	typedef IObserver<T> ObserverType;

	void RegisterObserver(ObserverType& observer, uint32_t priority) override {
		if (priority >= 5) return;
        if (matching_observers.count(& observer) > 0) return;

        m_observers[priority].insert(& observer);
	}

	void NotifyObservers() override {
		T data = GetChangedData();
		for (auto& observerPriority : m_observers) {
			for (auto& observer : observerPriority) {
				observer->Update(data);
			}
		}
	}

	void RemoveObserver(ObserverType& observer) override {
        if (matching_observers.count(& observer) == 0 ) return;
		matching_observers.erase(&observer);
		
		for (auto& observersRange : m_observers) {
            auto it = observersRange.find(& observer);
			if (it != matching_observers.end()) {
				observersRange.erase(it);
				return;
			}
		}
	}

protected:
	// Классы-наследники должны перегрузить данный метод, 
	// в котором возвращать информацию об изменениях в объекте
	virtual T GetChangedData()const = 0;

private:
	std::vector<std::set<ObserverType*> > m_observers;
	std::set<ObserverType*>matching_observers;
};
