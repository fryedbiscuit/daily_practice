import std;
import libc;

fn bool has_repeat(char[] line)
{
	for(int i = 0; i < (line.len - 2); i++){
		if (line[i] == line[i + 2])	return true;
	}
	return false;
}

fn bool has_pair(char [] line)
{
	for(int i = 0; i < (line.len - 1);i++){
		for(int j = i + 2;j < (line.len - 1);j++){
			if(line[i] == line[j]){
				if(line[i+1] == line[j+1]){
					return true;
				}
			}
		}
	}
	return false;
}

fn int main()
{
	File input = file::open("input.txt","r")!!;
	int good_lines = 0;
	while(true){
		@pool()
		{
			if(try String line = io::treadline(&input)){	
				if(has_pair(line) && has_repeat(line)){
	  			good_lines++;	
				};
			} else {
				break;
			}
		};
	}

	  io::printfn("Santa has %d good lines!",good_lines);

	return 0;
}
