#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

//fun��o de replace para trocar caracteres especiais dos arquivo layout
string replace(string & texto, const string& procurado, const string& troca) {
    int inicio_procurado = texto.find(procurado); //procura o local de inicio da string no vtor de char
    
    if(inicio_procurado == string::npos){ // verifcando se foi encontrado, se o npos retornar -1 siguinifica que nada foi encontrado
        return string(texto);	
	}

    texto.replace(inicio_procurado, procurado.length(), troca); // trocando o texto solictado, 
    
    if(texto.find(procurado) != string::npos){ // verifica se ap�s a troca ainda h� mais alguma coisa
    	return replace(texto, procurado, troca); // chama a fun��o de novo
	}
    
    return string(texto); // retorna a strin pronta
}


class ArquivosFontes{
	private:
		string nome; // nome do arquivo que vai ser criado
		string extensao; // exten~soa do arquivo
		string nomeInteiro; // variavel que guarda o nome com a extens�o ex: teste.js
		string local; // local aonde ser� guardado o arquivo
		
		void setNomeInteiro(){ // montando o nome inteiro do arquivo
			nomeInteiro = nome + "." + extensao;
		}
		
	public:
		// contrutor da classe, o local por padr�o � o local aonde o programa est� arqmazenado
		ArquivosFontes(string _nome, string _extensao, string _local = ""){ 
			setNome(_nome); // setando nome do arquivo
			setExtensao(_extensao);//setando extens�o
			setLocal(_local); // setando local
		}
		
		void setNome(string _nome){
			nome = _nome;
			setNomeInteiro();
		}
		
		void setExtensao(string _extensao){
			extensao = _extensao;
			setNomeInteiro();
		}

		void setLocal(string _local){
			local = _local;
		}
	
		string getNome(){
			return nome;
		}
		
		string getExtensao(){
			return extensao;
		}
		
		string getNomeInteiro(){
			return nomeInteiro;
		}
		
		string getLocal(){
			return local;
		}
		
		void print();
		int criarArquivo();
};


void ArquivosFontes::print(){
	string a = "guilherme";
	string extensao = ".lima";
	string dois = a + extensao;
	
	cout << dois << endl;
}

/*
Fun��o que criara  arquivo utiizando o seu arquivo layout e trocando as variaveis especiais contidas nele
*/
int ArquivosFontes::criarArquivo(){ 
	string arquivo = getNomeInteiro(), linhas, layout = "layout/layout." + getExtensao();
		
	ofstream novoArquivo; // instancia da classe ofstream para manipular arquivos
	novoArquivo.open(arquivo.c_str()); // abrindo e criando arquivo
	
	ifstream arquivoLayout(layout.c_str()); // abrindo arquivo de layout
	if(arquivoLayout.is_open()){ // verificando se o arquivo layout est� aberto
		
		while( getline(arquivoLayout, linhas) ){ // percorando linhas do arquivo layout
		// gravando linha a linha e trocando conteudos especiais do arquivo layout
		  novoArquivo << replace(linhas, "$[name_class]", getNome()) << endl; 
		}
		//fechando arquivo layout
		arquivoLayout.close();
	}
	
	else cout << "N�o foi possivel abrir o arquivo"; 

	//fechando novo arquivo
	novoArquivo.close();
		
   return 1;
}













