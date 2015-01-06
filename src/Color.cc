#include "Color.h"

Color Color::BLACK = Color(false);
Color Color::WHITE = Color(true);



Color::Color(bool a_isWhite) {
	isWhite = a_isWhite;
}


bool Color::isBlack() const {
	return !isWhite;
}

