import std;
import libc;

bool[1000][1000] lights;

fn void do_cmd(ZString cmd,int sx,int sy,int ex,int ey){
	io::printfn("%s: %d,%d -> %d,%d", cmd,sx,sy,ex,ey);
	for( int x = sx; x <= ex; x++){
		for( int y = sy; y <= ey; y++){
			if (libc::strcmp(cmd,"turn on ") == 0){
				lights[x][y] = true;
			}
			if (libc::strcmp(cmd,"turn off ") == 0){
				lights[x][y] = false;
			}
			if (libc::strcmp(cmd,"toggle ") == 0){
				if(lights[x][y]){
					lights[x][y] = false;
				} else {
					lights[x][y] = true;
				}
			}
		}
	}
}

fn int count_lights(){
	int light_count = 0;
	for(int x = 0;x < 1000;x++){
		for(int y = 0;y < 1000;y++){
			if(lights[x][y]) light_count++;;
	}}
	return light_count;
}

fn void main(){
	CFile input  = libc::fopen("input.txt", "r");
	ZString buffer = (ZString)malloc(200);
	char* ret;

	while(libc::fgets(buffer,100,input)){
		@pool(){
			ZString cmd = (ZString)tmalloc(100);
			CInt sx,sy;
			CInt ex,ey;
			
			libc::sscanf(buffer,"%[^0-9]%d,%d through %d,%d", cmd,&sx,&sy,&ex,&ey);
			do_cmd(cmd,sx,sy,ex,ey);
		};
	}
	io::printn(count_lights());
}
