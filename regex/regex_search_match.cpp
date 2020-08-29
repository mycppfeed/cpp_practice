#include <iostream>
#include <string>
#include <regex>

/**
 * Regex documented:
 * (\w+):(\w+);
 *
*          1st Capturing Group (\w+)
*              \w+ matches any word character (equal to [a-zA-Z0-9_])
*                  + Quantifier — Matches between one and unlimited times, as many times as possible, giving back as needed (greedy)
*
*          : matches the character : literally (case sensitive)
*
*          2nd Capturing Group (\w+)
*              \w+ matches any word character (equal to [a-zA-Z0-9_])
*                  + Quantifier — Matches between one and unlimited times, as many times as possible, giving back as needed (greedy)
*
*          ; matches the character ; literally (case sensitive)
*/

void raw_string_literal() {
    assert( "((\\w+):(\\w+);)" != R"((\\w+):(\\w+);)");
    // TODO I didnt understand how to represent the LHS into raw string
    assert( "((\\w+):(\\w+);)" != R"(((\\w+):(\\w+);))");
    assert( "Hello" == R"(Hello)");
    assert( "(Hello)" == R"((Hello))");
}

void search_match_raw_string() {
    const std::string input = "ABC:1@   PQR:2;$&   XYZ:3!";

    auto tmp0 = "((\\w+):(\\w+);)";
    auto tmp1 = R"((\w+):(\w+);)";

    std::cout << "TMP 0 : " << tmp0 << std::endl;
    std::cout << "TMP 1 : " << tmp1 << std::endl;

    {
        const std::regex r0(tmp0);
        std::smatch m0;
        auto ret0 = std::regex_search(input, m0, r0);

        std::cout << " SizeOf m0 : " << m0.size() << std::endl;
    }

    {
        const std::regex r1(tmp1);
        std::smatch m1;
        auto ret1 = std::regex_search(input, m1, r1);

        std::cout << " SizeOf m1 : " << m1.size() << std::endl;
    }
}

/**
 * regex_iterator (C++11)
 *      iterates through all regex matches within a character sequence
 * regex_token_iterator (C++11)
 *      iterates through the specified sub-expressions within all regex matches in a given string or through unmatched substrings
 */

#define C_ALL(X) cbegin(X), cend(X)
void regex_iterator_token_iterator() {
    const std::string input = "ABC:1->   PQR:2;;;   XYZ:3<<<";
    const std::regex r(R"((\w+):(\d))");

    const std::vector<std::smatch> matches{
        std::sregex_iterator{C_ALL(input), r},
        std::sregex_iterator{}
    };

    assert(matches[0].str(0) == "ABC:1"
        && matches[0].str(1) == "ABC"
        && matches[0].str(2) == "1");
    assert(matches[1].str(0) == "PQR:2"
        && matches[1].str(1) == "PQR"
        && matches[1].str(2) == "2");
    assert(matches[2].str(0) == "XYZ:3"
        && matches[2].str(1) == "XYZ"
        && matches[2].str(2) == "3");

    // Note: vector<string> here, unlike vector<smatch> as in std::regex_iterator
    const std::vector<std::string> full_match{
        std::sregex_token_iterator{C_ALL(input), r, 0}, // Mark `0` here i.e. whole regex match
        std::sregex_token_iterator{}
    };
    assert((full_match == decltype(full_match){"ABC:1", "PQR:2", "XYZ:3"}));

    const std::vector<std::string> cptr_grp_1st{
        std::sregex_token_iterator{C_ALL(input), r, 1}, // Mark `1` here i.e. 1st capture group
        std::sregex_token_iterator{}
    };
    assert((cptr_grp_1st == decltype(cptr_grp_1st){"ABC", "PQR", "XYZ"}));

    const std::vector<std::string> cptr_grp_2nd{
        std::sregex_token_iterator{C_ALL(input), r, 2}, // Mark `2` here i.e. 2nd capture group
        std::sregex_token_iterator{}
    };
    assert((cptr_grp_2nd == decltype(cptr_grp_2nd){"1", "2", "3"}));

    const std::vector<std::string> inverted{
        std::sregex_token_iterator{C_ALL(input), r, -1}, // `-1` = parts that are not matched
        std::sregex_token_iterator{}
    };
    assert((inverted == decltype(inverted){
                            "",
                            "->   ",
                            ";;;   ",
                            "<<<",
                        }));
}

// std::regex_search:
//      returns true, IFF there is ATLEAST one match found in string
//      smatch will be populated with all matching captures
// std::regex_match:
//      returns true, IFF the input string exactly matches
//      smatch will be populated with all matching captures

void search_match() {
    const std::regex r_test0(R"((\w+):(\w+);)");
    const std::regex r_email(R"(\w+@\w+\.(?:com|in))");

    // smatch has matches, unmatched, prefix and suffix, which are std::match_results
    std::smatch match_serch;
    std::smatch match_match;
    std::smatch match_email;

    const std::string input = "ABC:1->   PQR:2;;;   XYZ:3<<<";
    const std::string email = "vishalchovatiya@ymail.com";

    auto ret_search = std::regex_search(input, match_serch, r_test0);
    auto ret_match  = std::regex_match(input,  match_match, r_test0);
    auto ret_email  = std::regex_match(email,  match_email, r_email);

    assert( ret_search == true ),  assert( match_serch.size()  == 3 );
    assert( ret_match  == false ), assert( match_match.size()  == 0 );
    assert( ret_email  == true ),  assert( match_email.size()  == 1 );

    assert( match_serch[0].str() == "PQR:2;" );                // Entire match_serch
    assert( match_serch[1].str() == "PQR" );                   // Substring that match_serch 1st group
    assert( match_serch[2].str() == "2" );                     // Substring that match_serch 2nd group
    assert( match_serch.prefix().str() == "ABC:1->   " );      // All before 1st character match_serch
    assert( match_serch.suffix().str() == ";;   XYZ:3<<<" );   // All after last character match


    std::cout << " SizeOf Search Match : " << match_serch.size() << std::endl;
    std::cout << " SizeOf Match  Match : " << match_match.size()  << std::endl;

    // smatch has overload to access all matches as strings
     for (std::string &&str : match_serch) {
         std::cout << str << std::endl;
     }
}

int main() {
//    search_match();
    regex_iterator_token_iterator();
//    search_match_raw_string();
//    raw_string_literal();
    return EXIT_SUCCESS;
}
