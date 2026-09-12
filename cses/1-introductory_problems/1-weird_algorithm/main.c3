import std;


fn void main(){
	ulong n = io::treadline().to_ulong()!!;

	while(n != 1){
		io::printf("%d ",n);
		if(n % 2){
			n = (n * 3) + 1;
		} else {
			n = n / 2;
		}
	}
	io::printn(n);
}
