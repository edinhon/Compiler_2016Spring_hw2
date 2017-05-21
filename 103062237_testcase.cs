/*Advanced part testcase for 103062237*/

int num_one(){
	return 1;
}

int main(){
	
	/*Initialize by function invocation*/
	int i = num_one();
	
	/*Non Strict Order*/
	i = 0;
	int j = num_one();
	j = 0;
	
	/*if-else statement*/
	if(i){
		if(i){}
		else {}
	} else {
		if(j){}
		else {}
	}
	
	/*switch statement*/
	switch(i){
		int k = 0;
		k = num_one();
		case 1:
			k = num_one();
			break;
		case 2:{
			int l = 0;
			l = num_one();
			break;
		}
		default:
			break;
	}
	
	/*for statement*/
	for( i = 0, j = num_one() ; i < 10 && j < 10 ; i++, j++ ){
		i++;
		j++;
	}
	
	return 0;
	
}
