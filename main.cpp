#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <cassert>

void draw(auto min,auto higher){
	auto pas=2;
	int i=0;
	while(i<100){
		if (i< min) std::cout<<"-";
		else {
			if (i< higher) std::cout<<"|";
			else std::cout<<"x";
		}
		i=i+pas;
	}	
	std::cout<<'\n';
}

void draw_scale(){
	auto pas=2;
	int i=0;
	while(i<100){
		std::cout<<i/10;
		i=i+pas;
	}	
	std::cout<<'\n';
}

 int main(int argc, char* argv[]) {
	 if (argc < 5) {
        std::cerr << "5 chiffres, separé dun espace, de 5* à 1*"  <<'\n';
        return 1;
    }
	 std::cout<<"Excellent : "<<argv[1] <<'\n';
	 std::cout<<"Bon : "<<argv[2] <<'\n';
	 std::cout<<"Acceptable : "<<argv[3] <<'\n';
	 std::cout<<"mauvais : "<<argv[4] <<'\n';
	 std::cout<<"pitoyable : "<<argv[5] <<'\n'<<'\n';
	 
	 std::string::size_type sz;   // alias of size_t


	 auto excellent=std::stoi (argv[1],&sz);
	 auto bon=std::stoi (argv[2],&sz);
	 auto moyen=std::stoi (argv[3],&sz);
	 auto faible=std::stoi (argv[4],&sz);
	 auto mauvais=std::stoi (argv[5],&sz);
	 
	 
	 auto nb=excellent+bon+moyen+faible+mauvais;
	 
	 
	 auto ok= excellent+bon;
	 auto okpct=(double)ok/nb*100;
	 
	 auto ex_in_ok=(double)excellent/ok*100;
		 
	 auto moyenpct=(double)moyen/nb*100;
	
	 auto ko=faible+mauvais;
	 auto kopct=(double)ko/nb*100;
	 auto mauvais_in_ko=(double)mauvais/ko*100;
		 
	 std::cout<<"ok " << okpct << " _ " << ex_in_ok<< "|"<< moyenpct <<"|"<< kopct<<" _ "<< mauvais_in_ko<<'\n'<<'\n';
	draw_scale();
	draw((double)excellent/nb*100,okpct);
	draw(0,moyenpct);
	 draw((double)mauvais/nb*100,kopct);
	return 0;
}
