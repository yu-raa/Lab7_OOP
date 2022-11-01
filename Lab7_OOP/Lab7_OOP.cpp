#include <iostream>
#include <fstream>
#include <string>

template <class T>
class ReadWrite
{
private:
    T* arra;
    int sizee;
public:

    T* getArr()
        const
    {
        return arra;
    }

    int getSize()
        const
    {
        return sizee;
    }

    ReadWrite(T* arr, int size)
    {
        arra = arr;
        sizee = size;
    }

    ReadWrite() {}

    friend std::ostream& operator <<(std::ostream& streamo, const ReadWrite& obj)
    {
        try
        {
            streamo << (*(obj.getArr())).to_string();
        }
        catch (std::exception exc)
        {
            streamo << std::to_string(*(obj.getArr()));
        }
        int ind = 1;
        while (ind < obj.getSize())
        {
            try
            {
                streamo << ", " << (*(obj.getArr() + ind++)).to_string();
            }
            catch (std::exception exc)
            {
                streamo << ", " << std::to_string(*(obj.getArr() + ind++));
            }
        }

        return streamo;
    }
};

class Book
{
public:
    Book(int yearOfPub, std::string titleetc, double moneyFor)
    {
        year = (yearOfPub > 2022) ? 2022 : yearOfPub;
        titleAuthorPublishing = (titleetc == "") ? "none" : titleetc;
        price = (moneyFor < 0) ? 0 : moneyFor;
    }

    Book(int yearOfPub, double moneyFor) :Book(yearOfPub, "", moneyFor) {}

    Book(std::string titleetc, double moneyFor) :Book(2022, titleetc, moneyFor)
    {
    }

    Book(int yearOfPub, std::string titleetc) :Book(yearOfPub, titleetc, 0)
    {
    }

    Book(int yearOfPub) :Book(yearOfPub, "", 0)
    {
    }

    Book(std::string titleetc) :Book(2022, titleetc, 0)
    {

    }

    Book(double moneyFor) : Book(2022, "", moneyFor)
    {

    }

    Book() {}
    ~Book() {}

    void setYear(int yearOfPublish)
    {
        if (yearOfPublish <= 2022)
        {
            year = yearOfPublish;
        }
        else
        {
            std::cout << "\nThis year hasn't happened yet\n";
        }
    }

    int getYear()
    {
        return year;
    }

    void setTitleEtc(std::string titleAuthorPub)
    {
        if (titleAuthorPub == "")
        {
            std::cout << "\nNo title, author or publishing has been passed\n";
        }
        else
        {
            titleAuthorPublishing = titleAuthorPub;
        }
    }

    std::string getTitleEtc()
    {
        return titleAuthorPublishing;
    }

    void setPrice(double prices)
    {
        if (prices < 0)
        {
            std::cout << "\nPrice can't be negative\n";
        }
        else
        {
            price = prices;
        }
    }

    double getPrice()
    {
        return price;
    }

    std::string to_string()
    {
        return "\nBook " + this->getTitleEtc() + " of year " + std::to_string(this->getYear()) + " and price of $" + std::to_string(this->getPrice()) + "\n";
    }

    bool operator !=(Book anotherBook)
    {
        return (year != anotherBook.year || titleAuthorPublishing != anotherBook.titleAuthorPublishing || price != anotherBook.price);
    }



private:
    int year = 2022;
    std::string titleAuthorPublishing = "none";
    double price = 0;
};

int main()
{
    std::cout << ReadWrite<int>(new int[6] {2, 1, 4, 3, 6, 10}, 6);
    std::cout << ReadWrite<Book>(new Book[3]{ Book("hi"), Book(2010), Book(12.5) }, 3);
}