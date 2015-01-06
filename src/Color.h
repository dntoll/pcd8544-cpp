#pragma once


class Color {
	public:
		bool isWhite;
		Color(bool isOn);

		bool isBlack() const;

		static Color BLACK;
		static Color WHITE;
};


