#ifndef EMPRESA_H_INCLUDED
#define EMPRESA_H_INCLUDED
#include <vector>
#include <cstdint>

class Empresa {
private:
    std::string nome;
    uint64_t CEP;
    uint64_t telefone;
public:
    Empresa(): nome(""), CEP(0),telefone(0){}

    Empresa(std::string novoNome, uint64_t novoCEP, uint64_t novoTelefone){
        nome = novoNome;
        CEP = novoCEP;
        telefone = novoTelefone;
    }

    std::string getNome() const{
        return nome;
    }

    void setNome(std::string novoNome){
        nome = novoNome;
    }

    uint64_t getCEP() const{
        return CEP;
    }

    void setCEP(uint64_t novoCEP){
        CEP = novoCEP;
    }

    uint64_t getTelefone() const{
        return telefone;
    }

    void setTelefone(uint64_t novoTelefone){
        telefone = novoTelefone;
    }

    friend std::ostream& operator<<(std::ostream& X, const Empresa& emp)
    {
        return X << "Nome: " << emp.getNome() << " CEP: " << emp.getCEP() << " Telefone: " << emp.getTelefone();
    }

};

class Prato {
private:
    std::string nome;
    double preco;
public:
    void setNome(std::string novoNome){
        nome = novoNome;
    }

    std::string getNome() const{
        return nome;
    }

    void setPreco(double novoPreco){
        preco = novoPreco;
    }

    double getPreco() const{
        return preco;
    }


};

class Restaurante: public Empresa {
private:
    std::vector<Prato> menu;

public:
    Restaurante(): Empresa(), menu(){}

    Restaurante(std::string novoNome, uint64_t novoCEP, uint64_t novoTelefone):
        Empresa(novoNome,novoCEP,novoTelefone),menu(){
    }

    int size() const{
        return menu.size();
    }

    Prato getPrato(int i) const {
        if(i < 0 || i>=(int)menu.size()){
            std::cerr << "Prato inexistente\n";
            return Prato();
        }
        return menu[i];
    }

    void push_back(const Prato& prato){
        menu.push_back(prato);
    }

    void erase(int i){
        if (i<0 || i>=(int)menu.size())
        {
            std::cerr << "Prato inexistente\n";
            return;
        }
        menu.erase(menu.begin()+i);
    }

    void imprimirPratos() const{
        for (const auto& P : menu)
        {
            std::cout << P.getNome() << '\t' << P.getPreco()<< "\n";
        }
    }

    friend std::ostream& operator<<(std::ostream& X, const Restaurante& res)
    {
        return X << "Nome: " << res.getNome() << " CEP: " << res.getCEP() << " Telefone: " << res.getTelefone();
    }




};




#endif // EMPRESA_H_INCLUDED
