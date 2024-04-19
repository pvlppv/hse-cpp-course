#ifndef SOLUTION_H
#define SOLUTION_H

#include <algorithm>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

enum class CitationType
{
    WebPage,
    Article
};

class Citation
{
public:
    Citation(const std::string& title, int year)
        : _title(title), _year(year)
    {
    }

    virtual ~Citation() {}
    virtual void printCitation(std::ostream& ostr) const = 0;
    virtual std::string getInlineCitation() const = 0;
    virtual CitationType getType() const = 0;
    virtual std::string getInfo() const = 0;

protected:
    std::string _title;
    int _year;
};


class PublishedWork : public Citation
{
public:
    PublishedWork(const std::string& title, int year, const std::string& firstname, const std::string& lastname)
        : Citation(title, year)
    {
        _firstname = firstname;
        _lastname = lastname;
    }

protected:
    std::string _firstname;
    std::string _lastname;
};


class Article : public PublishedWork
{
public:
    Article(const std::string& title, int year, const std::string& firstname, const std::string& lastname, const std::string& journal)
        : PublishedWork(title, year, firstname, lastname)
    {
        _journal = journal;
    }

    void printCitation(std::ostream& ostr) const override
    {
        ostr << "Title: " << _title << std::endl;
        ostr << "Year: " << _year << std::endl;
        ostr << "Author: " << _firstname << " " << _lastname << std::endl;
        ostr << "Journal: " << _journal << std::endl;
    }

    std::string getInlineCitation() const override
    {
        return "[" + _lastname + ", " + std::to_string(_year) + "]";
    }

    CitationType getType() const override
    {
        return _type;
    }

    std::string getInfo() const override
    {
        return _lastname;
    }

protected:
    std::string _journal;
    CitationType _type = CitationType::Article;
};


// example 1 - Web Page
// you will need to modify it
class WebPage : public Citation
{
public:
    WebPage(const std::string& title, int year, const std::string& url)
        : Citation(title, year),
          _url(url)
    {
    }

    void printCitation(std::ostream& ostr) const override
    {
        ostr << "Title: " << _title << std::endl;
        ostr << "Year: " << _year << std::endl;
        ostr << "URL: " << _url << std::endl;
    }

    std::string getInlineCitation() const override
    {
        return "[Web page, " + std::to_string(_year) + "]";
    }

    CitationType getType() const override
    {
        return _type;
    }

    std::string getInfo() const override 
    {
        return _title;
    }

protected:
    std::string _url;
    CitationType _type = CitationType::WebPage;
};


// example 2 - Book
// included only as an example, not used in the tasks
class Book : public PublishedWork
{
public:
    Book(const std::string& title, int year, const std::string& firstname, const std::string& lastname, const std::string& publisher)
        : PublishedWork(title, year, firstname, lastname),
          _publisher(publisher)
    {
    }

    void printCitation(std::ostream& ostr) const override
    {
        PublishedWork::printCitation(ostr);
        ostr << "Publisher:" << _publisher << std::endl;
    }

protected:
    std::string _publisher;
};


// task 2
Citation* addCitation(std::map<std::string, Citation*>& citations, CitationType type, const std::map<std::string, std::string> data)
{
    Citation* citationToAdd;

    if (type == CitationType::WebPage)
    {
        citationToAdd = new WebPage(data.at("title"), std::stoi(data.at("year")), data.at("url"));
    }
    else if (type == CitationType::Article)
    {
        citationToAdd = new Article(data.at("title"), std::stoi(data.at("year")), data.at("firstname"), data.at("lastname"), data.at("journal"));
    }
    
    citations[data.at("key")] = citationToAdd;
    
    return citationToAdd;
}


// task 4
void insertInlineCitations(std::string& text, const std::map<std::string, Citation*>& citations)
{
    for (size_t i = 0; i < text.size(); i++)
    {
        if (text[i] == '{')
        {
            std::string citationKey;
            size_t j = i;
            while (j < text.size() && text[j] != '}')
            {
                citationKey += text[j];
                j++;
            }
            citationKey += text[j];
            if (j < text.size())
            {
                text.replace(i, j - i + 1, citations.at(citationKey)->getInlineCitation());
            }
        }
    }
}


// task 5
void printBibliographyAppearance(std::string& text, const std::map<std::string, Citation*>& citations)
{
    std::vector<std::string> passed;
    int counter = 1;
    for (size_t i = 0; i < text.size(); i++)
        {
            if (text[i] == '{')
            {
                std::string citationKey;
                size_t j = i;
                while (j < text.size() && text[j] != '}')
                {
                    citationKey += text[j];
                    j++;
                }
                citationKey += text[j];
                if (std::find(passed.begin(), passed.end(), citationKey) == passed.end())
                {
                    passed.push_back(citationKey); 
                    std::cout << counter << "." << std::endl;
                    citations.at(citationKey)->printCitation(std::cout);
                    counter++;
                }
            }
        }
}


// task 6
// you may modify classes in any way you want to solve this task
// you may add additional functions
bool sortCitations(std::pair<std::string, std::string>& citation1, std::pair<std::string, std::string>& citation2)
{
    return citation1.second < citation2.second;
}

void replaceCitations(std::string& text, const std::map<std::string, std::string>& map) 
{
    for (size_t i = 0; i < text.size(); i++)
    {
        if (text[i] == '{')
        {
            std::string citationKey;
            size_t j = i;
            while (j < text.size() && text[j] != '}')
            {
                citationKey += text[j];
                j++;
            }
            citationKey += text[j];
            if (j < text.size())
            {
                text.replace(i, j - i + 1, "[" + map.at(citationKey) + "]");
            }
        }
    }

}

void insertInlineAlphabetical(std::string& text, const std::map<std::string, Citation*>& citations)
{
    std::vector<std::string> passed;
    std::vector<std::pair<std::string, std::string>> citationsWeb, citationsArt;
    for (size_t i = 0; i < text.size(); i++)
    {
        if (text[i] == '{')
        {
            std::string citationKey;
            size_t j = i;
            while (j < text.size() && text[j] != '}')
            {
                citationKey += text[j];
                j++;
            }
            citationKey += text[j];
            if (std::find(passed.begin(), passed.end(), citationKey) == passed.end())
            {
                passed.push_back(citationKey);
                if (citations.at(citationKey)->getType() == CitationType::Article)
                {
                    citationsArt.push_back(std::make_pair(citationKey, citations.at(citationKey)->getInfo()));
                }
                else
                {
                    citationsWeb.push_back(std::make_pair(citationKey, citations.at(citationKey)->getInfo()));
                }
            }
        }
    }

    std::sort(citationsArt.begin(), citationsArt.end(), sortCitations);
    std::sort(citationsWeb.begin(), citationsWeb.end(), sortCitations);
    
    std::map<std::string, std::string> map;
    for (size_t i = 0; i < citationsArt.size(); i++)
    {
        map[citationsArt[i].first] = std::to_string(i + 1);
    }
    for (size_t i = 0; i < citationsWeb.size(); i++)
    {
        map[citationsWeb[i].first] = std::to_string(i + citationsArt.size() + 1);
    }

    replaceCitations(text, map);
}

#endif