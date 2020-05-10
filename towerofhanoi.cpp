#include<bits/stdc++.h>
using namespace std;

void toh(int n, char src, char aux, char dtn){

	if (n==1){
		cout<<"Move 1 from "<<src<<" to "<<dtn<<endl;
		return;
	}
	toh(n-1,src,dtn,aux);
	cout<<"Move "<<n<<" from "<<src<< " to "<<dtn<<endl;
	toh (n-1, aux, src, dtn);
}

int main(){
	int n=3;
	toh(n, 'A','B','C');
}