int balance;
pthread_cond_t sufficient_balance;
pthread_mutex_t mlock;

initialise() {
	pthread_mutex_init(&mlock, NULL);
	pthread_cond_init(&sufficient, NULL);
}

void deposit(int amt) {
	pthread_mutex_lock(&mlock);
	balance += amt;
		pthread_cond_broadcast(&sufficient_balance);
	pthread_mutex_unlock(&mlock);
}

void withdraw(int amt) {
	pthread_mutex_lock(&mlock);
		//if (amt > balance) pthread_cond_wait(&sufficient_balance);
		while(amt >= balance) pthread_cond_wait(&sufficient_balance);
	balance -= amt;
	pthread_mutex_unlock(&mlock);
}

finalize() {
	pthread_mutex_destroy(&mlock);
	pthread_cond_destroy(&sufficient);
}