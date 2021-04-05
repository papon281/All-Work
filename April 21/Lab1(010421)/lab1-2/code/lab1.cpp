// lab1.cpp : stable partition
// Two algorithms: iterative and divide-and-conquer

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <iomanip>
#include <functional>
#include <cassert>

/****************************************
 * Declarations                          *
 *****************************************/

// generic class to write an item to a stream
template <typename T>
class Formatter
{
public:
    Formatter(std::ostream& os, int width, int per_line)
        : os_{os}, per_line_{per_line}, width_{width}
    {
    }

    void operator()(const T& t)
    {
        os_ << std::setw(width_) << t;
        if (++outputted_ % per_line_ == 0)
            os_ << "\n";
    }

private:
    std::ostream& os_;    // output stream
    const int per_line_;  // number of columns per line
    const int width_;     // column width
    int outputted_{0};    // counter of number of items written to os_
};

/* *************************************** */

namespace TND004
{
    // Iterative algorithm
    void stable_partition_iterative(std::vector<int>& V, std::function<bool(int)> p);


    // Auxiliary function that performs the stable partition recursively
    std::vector<int>::iterator stable_partition(std::vector<int>::iterator first,
        std::vector<int>::iterator last,
        std::function<bool(int)> p);


    // Divide-and-conquer algorithm
    void stable_partition(std::vector<int>& V, std::function<bool(int)> p)
    {
        std::vector<int>::iterator it,it1,it2;
        int mid;
        mid = V.size() / 2;
        it1 = TND004::stable_partition(std::begin(V), std::begin(V) + mid, p);
        it2 = TND004::stable_partition(std::begin(V) + mid, std::end(V), p);

        std::rotate(it1,begin(V)+ mid, it2);
        for(it = begin(V); it != end(V); it++){
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
} // namespace TND004

void execute(std::vector<int>& V, const std::vector<int>& res);

bool even(int i);

/****************************************
 * Main:test code                        *
 *****************************************/

int main()
{
    /*****************************************************
     * TEST PHASE 1                                       *
     ******************************************************/
    {
        std::cout << "TEST PHASE 1\n\n";

        std::vector<int> seq{1, 2};

        std::cout << "Sequence: ";
        std::copy(std::begin(seq), std::end(seq), std::ostream_iterator<int> {std::cout, " "});

        execute(seq, std::vector<int> {2, 1});

        std::cout << "\nEmpty sequence: ";
        std::vector<int> empty;

        execute(empty, std::vector<int> {});
    }

    /*****************************************************
     * TEST PHASE 2                                       *
     ******************************************************/
    {
        std::cout << "\n\nTEST PHASE 2\n\n";

        std::vector<int> seq{2};

        std::cout << "Sequence: ";
        std::copy(std::begin(seq), std::end(seq), std::ostream_iterator<int> {std::cout, " "});

        execute(seq, std::vector<int> {2});
    }

    /*****************************************************
     * TEST PHASE 3                                       *
     ******************************************************/
    {
        std::cout << "\n\nTEST PHASE 3\n\n";

        std::vector<int> seq{3};

        std::cout << "Sequence: ";
        std::copy(std::begin(seq), std::end(seq), std::ostream_iterator<int> {std::cout, " "});

        execute(seq, std::vector<int> {3});
    }

    /*****************************************************
     * TEST PHASE 4                                       *
     ******************************************************/
    {
        std::cout << "\n\nTEST PHASE 4\n\n";

        std::vector<int> seq{3, 3};

        std::cout << "Sequence: ";
        std::copy(std::begin(seq), std::end(seq), std::ostream_iterator<int>(std::cout, " "));

        execute(seq, std::vector<int> {3, 3});
    }

    /*****************************************************
     * TEST PHASE 5                                       *
     ******************************************************/
    {
        std::cout << "\n\nTEST PHASE 5\n\n";

        std::vector<int> seq{1, 2, 3, 4, 5, 6, 7, 8, 9};

        std::cout << "Sequence: ";
        std::copy(std::begin(seq), std::end(seq), std::ostream_iterator<int>(std::cout, " "));

        execute(seq, std::vector<int> {2, 4, 6, 8, 1, 3, 5, 7, 9});
    }

    /*****************************************************
     * TEST PHASE 6                                       *
     ******************************************************/
    {
        std::cout << "\n\nTEST PHASE 6: test with long sequence loaded from a file\n\n";

        std::ifstream file("../code/test_data.txt");

        if (!file)
        {
            std::cout << "Could not open test test_data.txt!!\n";
            return 0;
        }

        // read the input sequence from file
        std::vector<int> seq{std::istream_iterator<int>{file}, std::istream_iterator<int>()};
        file.close();

        std::cout << "Number of items in the sequence: " << seq.size() << '\n';

        // display sequence
        // std::for_each(std::begin(seq), std::end(seq), Formatter<int>(std::cout, 8, 5));

        // read the result sequence from file
        file.open("../code/test_result.txt");

        if (!file)
        {
            std::cout << "Could not open test_result.txt!!\n";
            return 0;
        }

        std::vector<int> res{std::istream_iterator<int>{file}, std::istream_iterator<int>()};

        std::cout << "Number of items in the result sequence: " << res.size() << '\n';

        // display sequence
        //std::for_each(std::begin(res), std::end(res), Formatter<int>(std::cout, 8, 5));

        assert(seq.size() == res.size());

        execute(seq, res);
    }
}

/****************************************
 * Functions definitions                 *
 *****************************************/

bool even(int i)
{
    return i % 2 == 0;
}

// Used for testing

void execute(std::vector<int>& V, const std::vector<int>& res)
{
    std::vector<int> _copy{V};

    std::cout << "\n\nIterative stable partition\n";
    TND004::stable_partition_iterative(V, even);
    assert(V == res);  // compare with the expected result

    std::cout << "Divide-and-conquer stable partition\n";
    TND004::stable_partition(_copy, even);
    assert(_copy == res);  // compare with the expected result
}


// Iterative algorithm
void TND004::stable_partition_iterative(std::vector<int>& V, std::function<bool(int)> p)
{

    std::vector<int>:: iterator it;
    it = stable_partition(std::begin(V), std::end(V), p);

    for(std::vector<int>:: iterator it1 = begin(V); it1 != it; it1++)
    {
        std::cout << *it1 << " ";
    }

    for(std::vector<int>:: iterator it1 = it; it1 != end(V); it1++)
    {
        std::cout << *it1 << " ";
    }
    std::cout<<std::endl;
    // IMPLEMENT before Lab1 HA
}

// Auxiliary function that performs the stable partition recursively
// Divide-and-conquer algorithm: stable-partition the sub-sequence starting at first and ending at
// last-1.
// If there are items with property p then return an iterator to the end of the block
// containing the items with property p. If there are no items with property p then return first.
std::vector<int>::iterator TND004::stable_partition(std::vector<int>::iterator first,
        std::vector<int>::iterator last,
        std::function<bool(int)> p)
{
    // IMPLEMENT
    if(first == last){
        return first;
    }
    else{
        return std::stable_partition(first,last,p);
    }
}  // end of function
