#ifndef ESCOLA_H_INCLUDED
#define ESCOLA_H_INCLUDED

class Data {
private:
    int dia,mes,ano;
public:
    Data():dia(0),mes(0),ano(0){}

    Data(int umDia, int umMes, int umAno):
        dia(umDia), mes(umMes), ano(umAno)
        {
    }

    void setDia(int umDia){
        dia = umDia;
    }

    int getDia() const{
        return dia;
    }

    void setMes(int umMes){
        mes = umMes;
    }

    int getMes() const{
        return mes;
    }

    void setAno(int umAno){
        ano = umAno;
    }

    int getAno() const{
        return ano;
    }

    bool dataValida(){
        return mes <= 12 && mes >= 1;
    }

    friend std::ostream& operator<<(std::ostream& X, const Data& dt)
    {
        return X << "Data: " << dt.getDia() << "/" << dt.getMes() << "/" << dt.getAno();
    }

    friend std::istream& operator>>(std::istream& X, Data& dt)
    {
    char barra1, barra2;
    std::cout << "Digite a data no formato dd/mm/aaaa: ";
    X >> dt.dia >> barra1 >> dt.mes >> barra2 >> dt.ano;
    if (barra1 != '/' || barra2 != '/')
    {
        X.setstate(std::ios::failbit);
    }
    return X;
    }
};


class Pessoa {
protected:
    std::string nome;
    Data dtnasc;

public:

    Pessoa():nome(""), dtnasc(){}

    Pessoa(std::string novoNome, Data novaDtnasc): nome(novoNome), dtnasc(novaDtnasc){

    }

    void setNome(std::string novoNome){
        nome = novoNome;
    }

    std::string getNome(){
        return nome;
    }

    void setDtnasc(Data novoDtnasc){
        dtnasc = novoDtnasc;
    }

    Data getDtnasc(){
        return dtnasc;
    }
};

class Aluno: public Pessoa {
private:
    uint64_t matricula;
public:
    Aluno():Pessoa(),matricula(0){}

    Aluno(std::string novoNome, Data novoDtnasc, uint64_t novaMatricula):
        Pessoa(novoNome, novoDtnasc), matricula(novaMatricula)
    {
        }
};

class Professor: public Pessoa {
private:
    string dep;


};




#endif // ESCOLA_H_INCLUDED
