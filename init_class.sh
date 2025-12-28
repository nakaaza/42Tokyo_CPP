#!/bin/bash

# 使い方チェック
if [ -z "$1" ]; then
	echo "Usage: $0 ClassName"
	exit 1
fi

CLASS_NAME="$1"
HPP_FILE="${CLASS_NAME}.hpp"
CPP_FILE="${CLASS_NAME}.cpp"

# インクルードガード用マクロ名（例: FooBar -> FOOBAR_HPP）
GUARD=$(echo "${CLASS_NAME}_HPP" | tr '[:lower:]' '[:upper:]')

# ヘッダファイル生成
cat > "$HPP_FILE" <<EOF
#ifndef ${GUARD}
# define ${GUARD}

class ${CLASS_NAME} {

private:
	

public:
	${CLASS_NAME}();
	${CLASS_NAME}(const ${CLASS_NAME} &src);
	${CLASS_NAME} &operator=(const ${CLASS_NAME} &rhs);
	~${CLASS_NAME}();

};

#endif // ${GUARD}
EOF

# 実装ファイル生成
cat > "$CPP_FILE" <<EOF
#include "${HPP_FILE}"
#include <iostream>

${CLASS_NAME}::${CLASS_NAME}() {
	std::cout << "Default ${CLASS_NAME} constructor called" << std::endl;
	return ; 
}

${CLASS_NAME}::${CLASS_NAME}(const ${CLASS_NAME} &src) {
	std::cout << "Copy ${CLASS_NAME} constructor called" << std::endl;
	*this = src;
}

${CLASS_NAME} &${CLASS_NAME}::operator=(const ${CLASS_NAME} &rhs) {
	std::cout << "${CLASS_NAME} copy assignment operator called" << std::endl;
	if (this != &rhs) {
		// TODO: copy member variables here
	}
	return *this;
}

${CLASS_NAME}::~${CLASS_NAME}() {
	std::cout << "${CLASS_NAME} destructor called" << std::endl;
	return ;
}
EOF
