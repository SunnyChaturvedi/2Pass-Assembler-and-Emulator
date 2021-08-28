/*
	@author -> Sunny Chaturvedi
	@ID -> 1801CS54
*/

#include<bits/stdc++.h>
using namespace std ;

map < string , string > Optab ; //Opcode to Name
int A = 0, B = 0, PC = 0 , SP = 0 ; // Different registers ;
int m[2000000] ;	//memory
int startingofdseg = -1 , endingofdseg = -1 ;
vector<string> Code ;
void initialise(){
	Optab["00"] = "ldc" ;
	Optab["01"] = "adc" ;
	Optab["02"] = "ldl" ;
	Optab["03"] = "stl" ;
	Optab["04"] = "ldnl" ;
	Optab["05"] = "stnl" ;
	Optab["06"] = "add" ;
	Optab["07"] = "sub" ;
	Optab["08"] = "shl" ;
	Optab["09"] = "shr" ;
	Optab["0A"] = "adj" ;
	Optab["0B"] = "a2sp" ;
	Optab["0C"] = "sp2a" ;
	Optab["0D"] = "call" ;
	Optab["0E"] = "return" ;
	Optab["0F"] = "brz" ;
	Optab["10"] = "brlz" ;
	Optab["11"] = "br" ;
	Optab["12"] = "halt" ;
}

string tohex(int n){
	unsigned int x = n ;
	string ans ;
	while( x != 0){
		int t = x % 16 ;
		if(t < 10)ans.push_back((char)(t + 48)) ;
		else ans.push_back((char)(t + 55)) ;
		x /= 16 ;
	}
	reverse(ans.begin() , ans.end()) ;
	if(ans.size() < 9){
		string z = "00000000" ;
		return z.substr(0,8-ans.size()) + ans ;
	}
	return ans ;
}

bool DotheOperation(int x , int val){
	switch (x) {
		case 0:
			B = A ;
			A = val ;
			break ;

		case 1:
			// B = A ;
			A += val ;
			break ;

		case 2:
			B = A ;
			A = m[SP + val] ;
			break ;


		case 3:
			m[SP + val] = A ;
			A = B ;
			break ;


		case 4:
			// B = A ;
			A = m[A + val] ;
			// cout << A <<"$";
			break ;

		case 5:
			m[A + val] = B ;
			// A = val ;
			break ;

		case 6:
			// B = A ;
			A += B ;
			break ;

		case 7:
			// B = A ;
			A = B - A ;
			break ;

		case 8:
			A = B << A ;
			break ;

		case 9:
			// B = A ;
			A = B >> A ;
			break ;

		case 10:
			SP += val ;
			break ;

		case 11:
			SP = A ;
			A = B ;
			break ;

		case 12:
			B = A ;
			A = SP ;
			break ;

		case 13:
			B = A ;
			A = PC ;
			PC += val ;
			break ;

		case 14:
			PC = A ;
			A = B ;
			break ;

		case 15:
			if(A == 0){
				PC += val ;
			}
			break ;

		case 16:
			if(A < 0){
				// cout << A <<" ";
				PC += val ;
			}
			break ;

		case 17:
			PC += val ;
			break ;

		case 18:
			return true ;
			break ;

		default :
			m[PC] = val ;
			break ;


	}
	return false ;
}

void show(bool ds){
	if(!ds){
		cout << "A = " << tohex(A) <<" ";
		cout << "B = " << tohex(B) <<" ";
		cout << "PC = " << tohex(PC) <<" ";
		cout << "SP = " << tohex(SP) <<" " ;
	}else {
		if(startingofdseg == -1){
			cout << "No Data Segment present !" << endl  ;
			return ;
		} 

		int j = 0 ;

		for(int i = startingofdseg ; i < endingofdseg ; i++ , j++){
			if(j % 4 == 0)printf("\n%08X" , j);
			printf(" %d",m[i]);
		}
		cout << endl ;
	}
}

string findcomplement(string s){
	string ans ;
	int t ;
	for(auto&c : s){
		if(c >= 'A')t = c - 'A' + 10 ;
		else t = c - '0' ;
		t = 15 - t ;
		char x ;
		if(t < 10)x = (char)(t + 48) ;
		else x = (char)(t + 55) ;
		ans.push_back(x) ;
	}
	return ans ;
}

int hex2Dec(string s){
	// cout << s <<" ";
	int sign = 1 ;
	if(s[0] >= '8' || (s[0] >= 'A' && s[0] <= 'F')){
		s = findcomplement(s) ;
		sign = -1 ;
	}
	int ans = 0 , t = 1;
	reverse(s.begin() , s.end()) ;
	for(auto&c : s){
		if(c >= 'A' && c <= 'F')ans += (c - 'A' + 10) * t ;
		else ans += (c - '0') * t ;
		t *= 16 ;
	}
	if(sign == 1)return ans ;
	return (ans + 1)*-1 ;
}

int main(int argc , char* argv[])
{
	char what ;
	cout << "Enter t for viewing entire trace OR d for viewing memory before and after execution\n" ;
	cin >> what ;
	what = tolower(what) ;
	string name = argv[1] ;
    int read;
	ifstream file(name, ios::in | ios::binary);
    while(file.read((char*)&read,sizeof(int)))
    { 
      Code.push_back(tohex(read)) ;
    }
    initialise() ;
    startingofdseg = hex2Dec(Code.back()) ;
    endingofdseg = Code.size() - 1 ;
    
    if(startingofdseg != -1){
    	for(int i = startingofdseg ; i < endingofdseg ; i++ ){
    		m[i] = hex2Dec(Code[i]) ;
    	}
    }
    if(what == 'd'){
    	cout << "Data Segment before Execution of Program :: " ;
    	show(true) ;
	}
    int count = 0 ;

    for(;PC < startingofdseg ;count++){
    	if(PC >= Code.size() || PC < 0){
    		cout << "Program Counter reaches out of bounds !";
    		break ;
    	}
    	string s = Code[PC] ;
    	int F = hex2Dec(s.substr(6,2)) , X = hex2Dec(s.substr(0,6)) ;
    	bool flag = DotheOperation(F , X) ;
    	PC++ ;
    	if(what == 't'){
    		show(false) ;
    		cout << Optab[s.substr(6,2)] <<" ";
    		if(F < 6 || (F == 10 || F == 13) || (F > 14 && F < 18)){
    			printf("%08X", X);
    		}
    		cout << endl ;
    	}
    	if(flag)break ;


    	if(count > 100000){
    		cout << endl ;
    		cout << "FAIL SAFE Initiated !! Infinite Loop may be present" ;
    		break ;
    	} 

    }
    cout << "Instructions Executed " << count << endl ;
    if(what == 'd'){

    	cout << "Data Segment after Execution of Program :: " ;
    	show(true) ;
    }

     
	return 0 ;
    
}
