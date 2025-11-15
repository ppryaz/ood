// Pattern Classic Factory
#include <vector>
#include <iostream>
#include <list>

using std::vector;
using std::cout;

class Document {
public:
	virtual ~Document() {};
	virtual void save() = 0;
	virtual void open() = 0;
};

class DocumentManager {
	std::list<Document*> docs;
	virtual Document* createDocument() = 0;
public:
	Document *newDocument() {
		Document *doc = createDocument();
		docs.push_back(doc);
		return doc;
	}
};

class TextDocument : public Document {
public:
	void save() override { std::cout << "save text doc\n"; };
	void open() override { std::cout << "open text doc\n"; };
};

class HtmlDocument : public Document {
public:
	void save() override { std::cout << "save html doc\n"; };
	void open() override { std::cout << "open html doc\n"; };
};

class TextDocumentManager : public DocumentManager {
	Document* createDocument() override { return new TextDocument; }
};

class HtmlDocumentManager : public DocumentManager {
	Document* createDocument() override { return new HtmlDocument; }
};

int main() {
	std::vector<Document*> documents;

	HtmlDocumentManager html_manager;
	TextDocumentManager text_manager;

	for (int i = 0; i < 5 ; ++i) {
		auto doc = html_manager.newDocument();
		documents.emplace_back(doc);
	}

	for (int i = 0; i < 5 ; ++i) {
		auto doc = text_manager.newDocument();
		documents.emplace_back(doc);
	}

	for (int i = 0; i < documents.size(); ++i ) {
		documents[i]->open();
		documents[i]->save();
	}
}