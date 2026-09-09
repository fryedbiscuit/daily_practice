import std;

fn ulong[] prime_sieve(ulong limit)
{
	@pool(){
		bool[] is_prime = mem::temp_array(bool, (long)limit);
		List{ulong} primes;

		is_prime[0..1] = false;
		is_prime[2..] = true;

		ulong num = 2;
		while(num < limit){
			if(is_prime[num]){
				primes.push(num);
				for(ulong n = num * 2; n < limit; n += num){
					is_prime[n] = false;
				}
			}
			num++;
		}
		return primes.to_array(mem);
	};
}

fn int main(){
	ulong[] primes = prime_sieve(2_000_000);
	ulong sum = 0;

	foreach (n: primes){
		sum += n;
	}

	io::printfn("Result is %d", sum);

	return 0;
}
