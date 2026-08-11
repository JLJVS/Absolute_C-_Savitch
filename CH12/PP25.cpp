#include <iostream>
#include <fstream>
#include <string>

using std::cout, std::endl;
using std::string, std::istream, std::ostream, std::istringstream, std::ostringstream;

bool read_int(int& value, const string& prompt,
              istream& in = std::cin, ostream& out = std::cout)
{
    string line;
    while (true)
    {
        out << prompt;
 
        // getline failing means end of input - stop, do not loop forever.
        if (!std::getline(in, line)) return false;
 
        istringstream iss(line);
        int v;
 
        // Two questions, both of which must be yes:
        //   (iss >> v)            - an integer was parsed at all
        //   (iss >> std::ws).eof()- and nothing but whitespace followed it
        //
        // The second is essential: "42abc" parses successfully as 42 and
        // leaves "abc" behind, because stopping at a character that cannot be
        // part of an integer is normal termination, not failure.
        if ((iss >> v) && (iss >> std::ws).eof())
        {
            value = v;
            return true;
        }
 
        out << "  not an integer, try again\n";
    }
}

void check(const char* label, const string& canned, bool expect_ok, int expect_val)
{
    istringstream in(canned);
    ostringstream sink;                 // swallow the prompts
    int v {0};
    bool ok = read_int(v, "> ", in, sink);
    bool pass = (ok == expect_ok) && (!ok || v == expect_val);
    cout << (pass ? "  PASS  " : "  FAIL  ") << label << "\n";
}

int main()
{
    check("plain integer",           "42\n",       true, 42);
    check("negative",                "-7\n",       true, -7);
    check("leading/trailing spaces", "   42   \n", true, 42);
    check("plus sign",               "+42\n",      true, 42);
    check("junk then valid",         "abc\n42\n",  true, 42);
    check("blank line then valid",   "\n42\n",     true, 42);
    check("trailing junk rejected",  "42abc\n7\n", true, 7);
    check("decimal rejected",        "3.7\n8\n",   true, 8);
    check("two numbers rejected",    "42 99\n5\n", true, 5);
    check("overflow rejected",       "99999999999999999999\n6\n", true, 6);
    check("end of input, no valid",  "abc\n",      false, 0);
    check("immediate EOF",           "",           false, 0);
}