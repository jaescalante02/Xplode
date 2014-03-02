

#include <string> 

namespace Xplode {

    class Token {

        public:

            Token(int l, int c, char* val) { line = l; column = c; value = val; }
            int line;
            int column;
            std::string value;

    };

}
