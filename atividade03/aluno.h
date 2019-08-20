#ifndef _aluno_H_
#define _aluno_H_

class Aluno {
	private:
		string nome;
		string mat;
	public:
		Aluno() {}
		Aluno(const char * nome, const char * mat) : nome(nome), mat(mat) {
		
		}
		
		friend class Arranjo<Aluno>;
};

template<>
void Arranjo<Aluno>::set(int idx, const Aluno & aluno) {
// atribua nome e mat do item do array a partir de aluno
}

template<>
void Arranjo<Aluno>::exibir() {
// exiba cada aluno do array no formato "idx : mat = nome"
}

#endif
