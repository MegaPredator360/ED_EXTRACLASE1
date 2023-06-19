

#include "sstring.h"

string sstring::deserialize(ifstream& in) {
	string r;

	size_t n = 0;
	in.read((char*)&n, sizeof(size_t));

	char* c = new char[n];
	in.read(c, (std::streamsize)n);
	r = string(c);
	delete c;
	if (!in.good())
		throw - 1;

	return r;
}

bool sstring::serialize(ofstream& out, const string& s) {
	bool r = true;

	// Primero, guarda la longitud de la hilera,
	// tomando en cuenta el caracter nulo de terminación.

	size_t n = s.length() + 1;
	out.write((char*)&n, sizeof(size_t));

	// Luego graba los caracteres componentes de la
	// hilera.

	out.write(s.c_str(), (std::streamsize)n);
	return out.good();
}

