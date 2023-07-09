#include "CheckInputType.hpp"

// AŞAĞIDA YER ALAN FONKSİYONLAR AYNI MANTIĞI PAYLAŞMAKTADIR.

// istringstream aslında bir string streamdir. Stream demek, bir veri akışı demektir.
// String stream ise, bir stringin içindeki verileri okumak için kullanılır.
// Burada, stringin sonundaki f harfini atıyoruz. Ardından, stringi float'a çevirmeye çalışıyoruz.
// std::noskipws, boşlukları atlamadan okumayı sağlar. Verileri okurken, boşlukları atlamaz.
// Ardından, float'a çevirmeye çalışır. Eğer başarılı olursa, iss.eof() true döner.
// Eğer başarılı olamazsa, iss.fail() true döner.
bool CheckInputType::isFloat(const std::string& str) {
	std::istringstream iss(str.end()[-1] == 'f' ? str.substr(0, str.length() - 1) : str);
	float f;
	iss >> std::noskipws >> f;
	return iss.eof() && !iss.fail();
}

bool CheckInputType::isDouble(const std::string& str) {
	std::istringstream iss(str.end()[-1] == 'f' ? str.substr(0, str.length() - 1) : str);
	long double d;
	iss >> std::noskipws >> d;
	return iss.eof() && !iss.fail();
}

bool CheckInputType::isInteger(const std::string& str) {
	std::istringstream iss(str);
	int i;
	iss >> std::noskipws >> i;
	return iss.eof() && !iss.fail();
}

bool CheckInputType::isNaN(const std::string& str) {
	return str == "nan" || str == "-nan" || str == "+nan";
}