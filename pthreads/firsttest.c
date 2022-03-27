// // /* ************************************************************************** */
// // /*                                                                            */
// // /*                                                        :::      ::::::::   */
// // /*   firsttest.c                                        :+:      :+:    :+:   */
// // /*                                                    +:+ +:+         +:+     */
// // /*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
// // /*                                                +#+#+#+#+#+   +#+           */
// // /*   Created: 2022/03/19 16:32:38 by aelabid           #+#    #+#             */
// // /*   Updated: 2022/03/19 19:47:04 by aelabid          ###   ########.fr       */
// // /*                                                                            */
// // /* ************************************************************************** */

// // #include<pthread.h>
// // #include<stdio.h>
// // #include<unistd.h>

// // void    *myturn()
// // {
// // 	int	i = 1;
	
// // 	while (i < 10)
// // 	{
// // 		//sleep(1);
// // 		printf("MY turn %d\n", i);
// // 		i++;
// // 	}
// // 	return (NULL); 
// // }

// // void    yourturn()
// // {
// // 	int	i = 1;
	
// // 	while (i < 3)
// // 	{
// // 		//sleep(2);
// // 		printf("Your turn %d\n", i);
// // 		i++; 
// // 	}
// // }

// // int	main()
// // {
// // 	pthread_t	newthread;
// // 	pthread_create(&newthread, NULL, myturn, NULL);
// // 	yourturn();
// // 	pthread_join(newthread, NULL);
// // }


// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>  //Header file for sleep(). man 3 sleep for details.
// #include <pthread.h>
  
// // A normal C function that is executed as a thread 
// // when its name is specified in pthread_create()
// void *myThreadFun(void *vargp)
// {
//     sleep(1);
//     printf("Printing GeeksQuiz from Thread \n");
//     return NULL;
// }
   
// int main()
// {
//     pthread_t thread_id;
//     printf("Before Thread\n");
//     pthread_create(&thread_id, NULL, myThreadFun, NULL);
//     pthread_join(thread_id, NULL);
//     printf("After Thread\n");
//     exit(0);
// }






// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <pthread.h>
  
// // Let us create a global variable to change it in threads
// int g = 0;
  
// // The function to be executed by all threads
// void *myThreadFun(void *vargp)
// {
//     // Store the value argument passed to this thread
//     int *myid = (int *)vargp;
  
//     // Let us create a static variable to observe its changes
//     static int s = 0;
  
//     // Change static and global variables
//     ++s; ++g;
  
//     // Print the argument, static and global variables
//     printf("Thread ID: %d, Static: %d, Global: %d\n", *myid, ++s, ++g);
// }
  
// int main()
// {
//     int i;
//     pthread_t tid;
  
//     // Let us create three threads
//     for (i = 0; i < 3; i++)
//         pthread_create(&tid, NULL, myThreadFun, (void *)&tid);
  
//     pthread_exit(NULL);
//     return 0;
// }


// # include<unistd.h> // pour s l e ep
// # include<pthread.h> // pthr ead_c r eat e , pthr ead_join , pthr ead_exit
// # include<stdio.h>
// void  *fonction(void  *arg)
// {
// 	printf( " pid du thread f i l s = %d\n" , (int)getpid( ) ) ;
// 	while ( 1 ) ; // for eve r
// 	return NULL;
// 	}
// 	int main ()
// 	{
// 	pthread_t thread ;
// 	printf ("pid de main = %d\n" , (int)getpid ()) ;
// 	pthread_create (&thread , NULL, fonction , NULL) ;
// 	while ( 1 ) ; // for eve r
// 	return 0 ;
// }
#include <stdio.h>
#include <pthread.h>
// using namespace std;
const int N=10;
void * writer_thread (void * arg) {
 int i;
 for (i = 0; i < N; i++)
 printf( " Thread enfant.\n");
 return NULL;
}
int main (int argc, char *argv[]) {
	int i;
	pthread_t writer_id;
	printf("/****Debut de main****/\n");
	pthread_create (&writer_id, NULL, writer_thread, NULL);
	pthread_join(writer_id,NULL);
	for(i = 0; i < N; i++)
		printf( "Thread Parent\n");
	printf("/****Fin de main****/");
	pthread_exit (NULL);
	return 0;
} 