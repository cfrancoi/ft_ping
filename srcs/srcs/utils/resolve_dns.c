#include <net/if.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <netdb.h>
#include <stdio.h>
#include <netinet/in.h>

// FIX clean me !
int resolve_dns(char *c_addr, struct in_addr *dst)
{
	struct addrinfo hints;
	struct addrinfo *result, *rp;
	int s;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;    /* Allow IPv4 or IPv6 */
	hints.ai_socktype = SOCK_RAW; /* Datagram socket */
	hints.ai_flags = AI_CANONNAME;
	hints.ai_canonname = NULL;
	hints.ai_protocol = IPPROTO_RAW; //change to 

	s = getaddrinfo(c_addr, NULL, &hints, &result);
   //s = getaddrinfo(argv[1], NULL, NULL, &result);
   if (s != 0) {
       fprintf(2, "getaddrinfo: %s\n", gai_strerror(s));
       return 1;
   }

   /* getaddrinfo() returns a list of address structures.
      Try each address until we successfully connect(2).
      If socket(2) (or connect(2)) fails, we (close the socket
      and) try the next address. */

   for (rp = result; rp != NULL; rp = rp->ai_next)
   {
		struct sockaddr_in* internet_addr = (struct sockaddr_in*) rp->ai_addr;

		/*fprintf(stdout, "address is: %s\n", inet_ntoa(internet_addr->sin_addr));
		*/

		char str[INET_ADDRSTRLEN];
		if (inet_ntop(AF_INET, &(internet_addr->sin_addr), str, INET_ADDRSTRLEN) < 0)
			return 1;
		fprintf(stdout, "address is: %s\n", str);
		fprintf(stdout, "dns is: %s\n", rp->ai_canonname);

		*dst = internet_addr->sin_addr;
		char hbuf[NI_MAXHOST];
		struct sockaddr *addr;     /* input */
		socklen_t addrlen = {0};

		addr = rp->ai_addr;
		if (getnameinfo(addr, addrlen, hbuf, sizeof(hbuf), NULL, 0, NI_NAMEREQD) != 0)
           printf("could not resolve hostname\n");
		else
		{
			printf("host=%s\n", hbuf);
			break;
		}
	

      /*if (connect(sfd, rp->ai_addr, rp->ai_addrlen) != -1)*/
          // break;                  /* Success */
		
   }

   freeaddrinfo(result); 

   return 0;

}