double Min(double A[],int i){
	double min;
	if(i==0) return A[0];
	else{
		min=Min(A,i-1);
		if(min>A[i]) return A[i];
		else return(min);
	}
}
 
