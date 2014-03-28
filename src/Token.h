

#include <string> 

#ifndef X_TOKEN_
#define X_TOKEN_

namespace Xplode {

    class Token {

        public:

            Token(int l, int c, char* val) { line = l; column = c; value = val; }
            int line;
            int column;
            std::string value;

    };

}


#endif
