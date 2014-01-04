/******************************************
#     wig compiler-A by:
#
#    David Thibodeau
#    Ioannis Fytilis
#    Sherry Shanshan Ruan
#  
#    copyright @ group-A 2013
#
 ******************************************/

/* Include library functions */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "wigA_run.c"

/* Booleans are represented as ints */

#define true 1
#define false 0

typedef int bool;

/* Define global variables */

char * url;
char * sessionid;
char gb_name[] = "../benchmark/GroupA.gb";

FILE *gf;
FILE *lf;

/* Wig html section */

void html_Input(char *url, char *sessionid)
{
	printf("Content-type: text/html\n\n");
	printf("<html>\n") ;
	printf("<form method=\"POST\" action=\"%s?%s\">\n", url, sessionid);
	printf("\n                         ");
	printf("<head>\n");
	printf("\n                             ");
	printf("<title>\n");
	printf("Welcome to group-a's wig service");
	printf("</title>\n");
	printf("\n                         ");
	printf("</head>\n");
	printf("\n                         ");
	printf("<body bgcolor=\"FFCCFF\">\n");
	printf("\n                         ");
	printf("<font face=\"arial\" color=\"660066\">\n");
	printf("\n                             ");
	printf("<center>\n");
	printf("<h1>\n");
	printf("Hello! Welcome to Our Wig Service");
	printf("</h1>\n");
	printf("\n                             ");
	printf("<h2>\n");
	printf("We are here to help you do all matrix calculation!");
	printf("</h2>\n");
	printf("<br>\n");
	printf("<br>\n");
	printf("\n                             ");
	printf("<table>\n");
	printf("\n\t\t\t         ");
	printf("<tr>\n");
	printf("\n\t\t\t             ");
	printf("<td colspan=\"2\" align=\"center\" valign=\"top\">\n");
	printf("<h3>\n");
	printf(" Please put your 3x3 int matrix here:");
	printf("</h3>\n");
	printf("</td>\n");
	printf("\n\t\t\t         ");
	printf("</tr>\n");
	printf("\n\t\t\t         ");
	printf("<tr>\n");
	printf("\n\t\t\t             ");
	printf("<td>\n");
	printf("<input type=\"text\" name=\"a11\" size=10>");
	printf("\n\t\t\t                 ");
	printf("<input type=\"text\" name=\"a12\" size=10>");
	printf("\n\t\t\t                 ");
	printf("<input type=\"text\" name=\"a13\" size=10>");
	printf("<br>\n");
	printf("<br>\n");
	printf("</td>\n");
	printf("\n\t\t\t         ");
	printf("</tr>\n");
	printf("\n\t\t\t         ");
	printf("<tr>\n");
	printf("\n\t\t\t             ");
	printf("<td>\n");
	printf("<input type=\"text\" name=\"a21\" size=10>");
	printf("\n\t\t\t                 ");
	printf("<input type=\"text\" name=\"a22\" size=10>");
	printf("\n\t\t\t                 ");
	printf("<input type=\"text\" name=\"a23\" size=10>");
	printf("<br>\n");
	printf("<br>\n");
	printf("</td>\n");
	printf("\n\t\t\t         ");
	printf("</tr>\n");
	printf("\n\t\t\t         ");
	printf("<tr>\n");
	printf("\n\t\t\t             ");
	printf("<td>\n");
	printf("<input type=\"text\" name=\"a31\" size=10>");
	printf("\n\t\t\t                 ");
	printf("<input type=\"text\" name=\"a32\" size=10>");
	printf("\n\t\t\t                 ");
	printf("<input type=\"text\" name=\"a33\" size=10>");
	printf("<br>\n");
	printf("<br>\n");
	printf("</td>\n");
	printf("\n\t\t\t         ");
	printf("</tr>\n");
	printf("\n\t\t             ");
	printf("</table>\n");
	printf("\n\t\t             ");
	printf("<p>\n");
	printf("<font color=\"black\">\n");
	printf("Please select the type of calculation you want to perform:");
	printf("</font>\n");
	printf("\n\t\t                 ");
	printf("<select name=\"from\" size=1>");	printf("\n\t                             ");
	printf("<option value=\"det\">\n");
	printf("Determinant");
	printf("</option>\n");
	printf("\n\t                             ");
	printf("<option value=\"tra\">\n");
	printf("Trace");
	printf("</option>\n");
	printf("\n\t                             ");
	printf("<option value=\"tran\">\n");
	printf("Transpose");
	printf("</option>\n");
	printf("\n\t                         ");
	printf("</select>");
	printf("<br>\n");
	printf("<br>\n");
	printf("\n\t                     ");
	printf("</p>\n");
	printf("\n\t                     ");
	printf("<p>\n");
	printf("<input type=\"radio\" name=\"quit\" value=\"1\">");
	printf("<font color=\"003333\">\n");
	printf("Exit the service");
	printf("</font>\n");
	printf("</p>\n");
	printf("\n                             ");
	printf("<i>\n");
	printf("Copyright @ Group A: David Thibodeau, Sherry Ruan, Ioannis Fytilis ");
	printf("</i>\n");
	printf("<br>\n");
	printf("\n                             ");
	printf("<i>\n");
	printf("Last Update: September 28 2013");
	printf("</i>\n");
	printf("</center>\n");
	printf("           \n                         ");
	printf("</font>\n");
	printf("          \n                         ");
	printf("</body>\n");
	printf("\n                     ");
	printf("<br><input type=\"submit\" value=\"Continue\">\n");
	printf("</form><html>\n");
}

void html_Det(char *url, char *sessionid, char *a31, char *a13, char *a11, char *a33, char *det, char *a12, char *a22, char *a32, char *a23, char *a21)
{
	printf("Content-type: text/html\n\n");
	printf("<html>\n") ;
	printf("<form method=\"POST\" action=\"%s?%s\">\n", url, sessionid);
	printf("\n                       ");
	printf("<head>\n");
	printf("\n                           ");
	printf("<title>\n");
	printf("Determinant");
	printf("</title>\n");
	printf("\n                       ");
	printf("</head>\n");
	printf("\n                       ");
	printf("<body bgcolor=\"FFCCFF\">\n");
	printf("\n                         ");
	printf("<font face=\"arial\" color=\"660066\">\n");
	printf("\n                             ");
	printf("<center>\n");
	printf("<h1>\n");
	printf("Hello! Welcome to Our Wig Service");
	printf("</h1>\n");
	printf("\n                             ");
	printf("<h2>\n");
	printf("We are here to help you do all matrix calculation!");
	printf("</h2>\n");
	printf("<br>\n");
	printf("<br>\n");
	printf("\n                             ");
	printf("<table>\n");
	printf("\n\t\t\t         ");
	printf("<tr>\n");
	printf("\n\t\t\t             ");
	printf("<td colspan=\"2\" align=\"center\" valign=\"top\">\n");
	printf("<h3>\n");
	printf(" The matrix you entered is:");
	printf("</h3>\n");
	printf("</td>\n");
	printf("\n\t\t\t         ");
	printf("</tr>\n");
	printf("\n\t\t\t         ");
	printf("<tr>\n");
	printf("\n\t\t\t             ");
	printf("<td>\n");
	printf("%s", a11);
	printf("</td>\n");
	printf("\n\t\t\t             ");
	printf("<td>\n");
	printf("%s", a12);
	printf("</td>\n");
	printf("\n\t\t\t             ");
	printf("<td>\n");
	printf("%s", a13);
	printf("</td>\n");
	printf("\n\t\t\t         ");
	printf("</tr>\n");
	printf("\n\t\t\t         ");
	printf("<tr>\n");
	printf("\n\t\t\t             ");
	printf("<td>\n");
	printf("%s", a21);
	printf("</td>\n");
	printf("\n\t\t\t             ");
	printf("<td>\n");
	printf("%s", a22);
	printf("</td>\n");
	printf("\n\t\t\t             ");
	printf("<td>\n");
	printf("%s", a23);
	printf("</td>\n");
	printf("\n\t\t\t         ");
	printf("</tr>\n");
	printf("\n\t\t\t         ");
	printf("<tr>\n");
	printf("\n\t\t\t             ");
	printf("<td>\n");
	printf("%s", a31);
	printf("</td>\n");
	printf("\n\t\t\t             ");
	printf("<td>\n");
	printf("%s", a32);
	printf("</td>\n");
	printf("\n\t\t\t             ");
	printf("<td>\n");
	printf("%s", a33);
	printf("</td>\n");
	printf("\n\t\t\t         ");
	printf("</tr>\n");
	printf("\n\t\t             ");
	printf("</table>\n");
	printf("\n\t\t             \n\t\t             ");
	printf("<h3>\n");
	printf("<font color=\"black\">\n");
	printf("The determinant is: ");
	printf("%s", det);
	printf("</font>\n");
	printf("</h3>\n");
	printf("<br>\n");
	printf("\n\t\t             \n\t\t             ");
	printf("<p>\n");
	printf("<font color=\"black\">\n");
	printf("Please select other type of calculation you want to perform:");
	printf("</font>\n");
	printf("\n\t\t                 ");
	printf("<select name=\"from\" size=1>");	printf("\n\t                             ");
	printf("<option value=\"det\">\n");
	printf("Determinant");
	printf("</option>\n");
	printf("\n\t                             ");
	printf("<option value=\"tra\">\n");
	printf("Trace");
	printf("</option>\n");
	printf("\n\t                             ");
	printf("<option value=\"tran\">\n");
	printf("Transpose");
	printf("</option>\n");
	printf("\n\t                         ");
	printf("</select>");
	printf("<br>\n");
	printf("<br>\n");
	printf("\n\t                     ");
	printf("</p>\n");
	printf("\n\t                     ");
	printf("<p>\n");
	printf("<input type=\"radio\" name=\"reset\" value=\"1\">");
	printf("<font color=\"003333\">\n");
	printf("Enter a new matrix");
	printf("</font>\n");
	printf("</p>\n");
	printf("\n\t                     ");
	printf("<p>\n");
	printf("<input type=\"radio\" name=\"quit\" value=\"1\">");
	printf("<font color=\"003333\">\n");
	printf("Exit the service");
	printf("</font>\n");
	printf("</p>\n");
	printf("\n                        \n                             ");
	printf("<i>\n");
	printf("Copyright @ Group A: David Thibodeau, Sherry Ruan, Ioannis Fytilis ");
	printf("</i>\n");
	printf("<br>\n");
	printf("\n                             ");
	printf("<i>\n");
	printf("Last Update: September 28 2013");
	printf("</i>\n");
	printf("</center>\n");
	printf("           \n                         ");
	printf("</font>\n");
	printf("        \n                         ");
	printf("</body>\n");
	printf("\n                     ");
	printf("<br><input type=\"submit\" value=\"Continue\">\n");
	printf("</form><html>\n");
}

void html_Tra(char *url, char *sessionid, char *a31, char *a13, char *a11, char *a33, char *tra, char *a12, char *a22, char *a32, char *a23, char *a21)
{
	printf("Content-type: text/html\n\n");
	printf("<html>\n") ;
	printf("<form method=\"POST\" action=\"%s?%s\">\n", url, sessionid);
	printf("\n                       ");
	printf("<head>\n");
	printf("\n                           ");
	printf("<title>\n");
	printf("Determinant");
	printf("</title>\n");
	printf("\n                       ");
	printf("</head>\n");
	printf("\n                       ");
	printf("<body bgcolor=\"FFCCFF\">\n");
	printf("\n                           ");
	printf("<font face=\"arial\" color=\"660066\">\n");
	printf("\n                             ");
	printf("<center>\n");
	printf("<h1>\n");
	printf("Hello! Welcome to Our Wig Service");
	printf("</h1>\n");
	printf("\n                             ");
	printf("<h2>\n");
	printf("We are here to help you do all matrix calculation!");
	printf("</h2>\n");
	printf("<br>\n");
	printf("<br>\n");
	printf("\n                             ");
	printf("<table>\n");
	printf("\n\t\t\t         ");
	printf("<tr>\n");
	printf("\n\t\t\t             ");
	printf("<td colspan=\"2\" align=\"center\" valign=\"top\">\n");
	printf("<h3>\n");
	printf("The matrix you entered is:");
	printf("</h3>\n");
	printf("</td>\n");
	printf("\n\t\t\t         ");
	printf("</tr>\n");
	printf("\n\t\t\t         ");
	printf("<tr>\n");
	printf("\n\t\t\t             ");
	printf("<td>\n");
	printf("%s", a11);
	printf("</td>\n");
	printf("\n\t\t\t             ");
	printf("<td>\n");
	printf("%s", a12);
	printf("</td>\n");
	printf("\n\t\t\t             ");
	printf("<td>\n");
	printf("%s", a13);
	printf("</td>\n");
	printf("\n\t\t\t         ");
	printf("</tr>\n");
	printf("\n\t\t\t         ");
	printf("<tr>\n");
	printf("\n\t\t\t             ");
	printf("<td>\n");
	printf("%s", a21);
	printf("</td>\n");
	printf("\n\t\t\t             ");
	printf("<td>\n");
	printf("%s", a22);
	printf("</td>\n");
	printf("\n\t\t\t             ");
	printf("<td>\n");
	printf("%s", a23);
	printf("</td>\n");
	printf("\n\t\t\t         ");
	printf("</tr>\n");
	printf("\n\t\t\t         ");
	printf("<tr>\n");
	printf("\n\t\t\t             ");
	printf("<td>\n");
	printf("%s", a31);
	printf("</td>\n");
	printf("\n\t\t\t             ");
	printf("<td>\n");
	printf("%s", a32);
	printf("</td>\n");
	printf("\n\t\t\t             ");
	printf("<td>\n");
	printf("%s", a33);
	printf("</td>\n");
	printf("\n\t\t\t         ");
	printf("</tr>\n");
	printf("\n\t\t             ");
	printf("</table>\n");
	printf("\n\t\t             ");
	printf("<h3>\n");
	printf("<font color=\"black\">\n");
	printf("The trace is: ");
	printf("%s", tra);
	printf("</font>\n");
	printf("</h3>\n");
	printf("<br>\n");
	printf("\n\t\t             ");
	printf("<p>\n");
	printf("<font color=\"black\">\n");
	printf("Please select other type of calculation you want to perform:");
	printf("</font>\n");
	printf("\n\t\t                 ");
	printf("<select name=\"from\" size=1>");	printf("\n\t                             ");
	printf("<option value=\"det\">\n");
	printf("Determinant");
	printf("</option>\n");
	printf("\n\t                             ");
	printf("<option value=\"tra\">\n");
	printf("Trace");
	printf("</option>\n");
	printf("\n\t                             ");
	printf("<option value=\"tran\">\n");
	printf("Transpose");
	printf("</option>\n");
	printf("\n\t                         ");
	printf("</select>");
	printf("<br>\n");
	printf("<br>\n");
	printf("\n\t                     ");
	printf("</p>\n");
	printf("\n\t                     ");
	printf("<p>\n");
	printf("<input type=\"radio\" name=\"reset\" value=\"1\">");
	printf("<font color=\"003333\">\n");
	printf("Enter a new matrix");
	printf("</font>\n");
	printf("</p>\n");
	printf("\n\t                     ");
	printf("<p>\n");
	printf("<input type=\"radio\" name=\"quit\" value=\"1\">");
	printf("<font color=\"003333\">\n");
	printf("Exit the service");
	printf("</font>\n");
	printf("</p>\n");
	printf("\n                             ");
	printf("<i>\n");
	printf("Copyright @ Group A: David Thibodeau, Sherry Ruan, Ioannis Fytilis ");
	printf("</i>\n");
	printf("<br>\n");
	printf("\n                             ");
	printf("<i>\n");
	printf("Last Update: September 28 2013");
	printf("</i>\n");
	printf("</center>\n");
	printf("           \n                         ");
	printf("</font>\n");
	printf("        \n                         ");
	printf("</body>\n");
	printf("\n                     ");
	printf("<br><input type=\"submit\" value=\"Continue\">\n");
	printf("</form><html>\n");
}

void html_Tran(char *url, char *sessionid, char *a31, char *a13, char *a11, char *a33, char *a12, char *a22, char *a32, char *a23, char *a21)
{
	printf("Content-type: text/html\n\n");
	printf("<html>\n") ;
	printf("<form method=\"POST\" action=\"%s?%s\">\n", url, sessionid);
	printf("\n                       ");
	printf("<head>\n");
	printf("\n                           ");
	printf("<title>\n");
	printf("Determinant");
	printf("</title>\n");
	printf("\n                       ");
	printf("</head>\n");
	printf("\n                       ");
	printf("<body bgcolor=\"FFCCFF\">\n");
	printf("\n                         ");
	printf("<font face=\"arial\" color=\"660066\">\n");
	printf("\n                             ");
	printf("<center>\n");
	printf("<h1>\n");
	printf("Hello! Welcome to Our Wig Service");
	printf("</h1>\n");
	printf("\n                             ");
	printf("<h2>\n");
	printf("We are here to help you do all matrix calculation!");
	printf("</h2>\n");
	printf("<br>\n");
	printf("<br>\n");
	printf("\n\t\t             ");
	printf("<table>\n");
	printf("\n\t\t\t         ");
	printf("<tr>\n");
	printf("\n\t\t\t             ");
	printf("<td colspan=\"2\" align=\"center\" valign=\"top\">\n");
	printf("<h3>\n");
	printf(" The transpose matrix is:");
	printf("</h3>\n");
	printf("</td>\n");
	printf("\n\t\t\t         ");
	printf("</tr>\n");
	printf("\n\t\t\t         ");
	printf("<tr>\n");
	printf("\n\t\t\t             ");
	printf("<td>\n");
	printf("%s", a11);
	printf("</td>\n");
	printf("\n\t\t\t             ");
	printf("<td>\n");
	printf("%s", a21);
	printf("</td>\n");
	printf("\n\t\t\t             ");
	printf("<td>\n");
	printf("%s", a31);
	printf("</td>\n");
	printf("\n\t\t\t         ");
	printf("</tr>\n");
	printf("\n\t\t\t         ");
	printf("<tr>\n");
	printf("\n\t\t\t             ");
	printf("<td>\n");
	printf("%s", a12);
	printf("</td>\n");
	printf("\n\t\t\t             ");
	printf("<td>\n");
	printf("%s", a22);
	printf("</td>\n");
	printf("\n\t\t\t             ");
	printf("<td>\n");
	printf("%s", a32);
	printf("</td>\n");
	printf("\n\t\t\t         ");
	printf("</tr>\n");
	printf("\n\t\t\t         ");
	printf("<tr>\n");
	printf("\n\t\t\t             ");
	printf("<td>\n");
	printf("%s", a13);
	printf("</td>\n");
	printf("\n\t\t\t             ");
	printf("<td>\n");
	printf("%s", a23);
	printf("</td>\n");
	printf("\n\t\t\t             ");
	printf("<td>\n");
	printf("%s", a33);
	printf("</td>\n");
	printf("\n\t\t\t         ");
	printf("</tr>\n");
	printf("\n\t\t             ");
	printf("</table>\n");
	printf("\n\t\t             ");
	printf("<p>\n");
	printf("<font color=\"black\">\n");
	printf("Please select other type of calculation you want to perform:");
	printf("</font>\n");
	printf("\n\t\t                 ");
	printf("<select name=\"from\" size=1>");	printf("\n\t                             ");
	printf("<option value=\"det\">\n");
	printf("Determinant");
	printf("</option>\n");
	printf("\n\t                             ");
	printf("<option value=\"tra\">\n");
	printf("Trace");
	printf("</option>\n");
	printf("\n\t                             ");
	printf("<option value=\"tran\">\n");
	printf("Transpose");
	printf("</option>\n");
	printf("\n\t                         ");
	printf("</select>");
	printf("<br>\n");
	printf("<br>\n");
	printf("\n\t                     ");
	printf("</p>\n");
	printf("\n\t                     ");
	printf("<p>\n");
	printf("<input type=\"radio\" name=\"reset\" value=\"1\">");
	printf("<font color=\"003333\">\n");
	printf("Enter a new matrix");
	printf("</font>\n");
	printf("</p>\n");
	printf("\n\t                     ");
	printf("<p>\n");
	printf("<input type=\"radio\" name=\"quit\" value=\"1\">");
	printf("<font color=\"003333\">\n");
	printf("Exit the service");
	printf("</font>\n");
	printf("</p>\n");
	printf("\n                             ");
	printf("<i>\n");
	printf("Copyright @ Group A: David Thibodeau, Sherry Ruan, Ioannis Fytilis ");
	printf("</i>\n");
	printf("<br>\n");
	printf("\n                             ");
	printf("<i>\n");
	printf("Last Update: September 28 2013");
	printf("</i>\n");
	printf("</center>\n");
	printf("           \n                         ");
	printf("</font>\n");
	printf("           \n                         ");
	printf("</body>\n");
	printf("\n                     ");
	printf("<br><input type=\"submit\" value=\"Continue\">\n");
	printf("</form><html>\n");
}

void html_Finish(char *url, char *sessionid)
{
	printf("Content-type: text/html\n\n");
	printf("<html>\n") ;
	printf("<form method=\"POST\" action=\"%s?%s\">\n", url, sessionid);
	printf("\n                          ");
	printf("<body bgcolor=\"FFCCFF\">\n");
	printf("\n                          ");
	printf("<center>\n");
	printf("<font face=\"arial\" color=\"660066\">\n");
	printf("\n                              ");
	printf("<h1>\n");
	printf("Thanks for the use. Hope you like our WIG service! ");
	printf("</h1>\n");
	printf("\n                              ");
	printf("<i>\n");
	printf("Copyright @ Group A: David Thibodeau, Sherry Ruan, Ioannis Fytilis ");
	printf("</i>\n");
	printf("<br>\n");
	printf("\n                              ");
	printf("<i>\n");
	printf("Last Update: September 28 2013");
	printf("</i>\n");
	printf("        \n                          ");
	printf("</font>\n");
	printf("</center>\n");
	printf("\n                          ");
	printf("</body>\n");
	printf(" \n                      ");
	printf("<br><input type=\"submit\" value=\"Continue\">\n");
	printf("</form><html>\n");
}

/* Wig session section */

void session_Start(int stage)
{
	int a11, a12, a13, a21, a22, a23, a31, a32, a33;
	int det, tra;
	int quit, reset;
	char *from = "";

	/* Control flow for different stages */
	int step = 0;
	if (stage == 0) goto step_0;

	/* Get the stage where we branch from the file */
	lf = fopen(sessionid, "r");
	step = fgetc(lf);
	fclose(lf);
	if (step == 1) goto step_1;
	if (step == 2) goto step_2;
	if (step == 3) goto step_3;
	if (step == 4) goto step_4;
	exit(1);

/* step_0 : first time into this session */
step_0:

	/* Create a new sessionid for the connection to store locals and globals */
	sessionid = randomString("Start", 20);

	/* Read all global variables first */
	gf = fopen(gb_name, "r");
	if (gf != NULL)
	{
		fclose(gf);
	}

	quit = 0;
	reset = 1;

	while(quit!=1)
	{

		if(reset==1)
		{
			
			/* Write local variables into temp file */
			lf = fopen(sessionid, "w");
			fputc(1, lf);
			fwrite(&a32, sizeof(int), 1, lf);
			fwrite(&reset, sizeof(int), 1, lf);
			fwrite(&a33, sizeof(int), 1, lf);
			fwrite(&a13, sizeof(int), 1, lf);
			fwrite(&a31, sizeof(int), 1, lf);
			fwrite(&a21, sizeof(int), 1, lf);
			fwrite(&a23, sizeof(int), 1, lf);
			fwrite(&a22, sizeof(int), 1, lf);
			{
				int tmpi;
				tmpi = strlen(from);
				fwrite(&tmpi, sizeof(int), 1, lf);
				fwrite(from, sizeof(char), strlen(from), lf);
			}
			fwrite(&a12, sizeof(int), 1, lf);
			fwrite(&tra, sizeof(int), 1, lf);
			fwrite(&quit, sizeof(int), 1, lf);
			fwrite(&det, sizeof(int), 1, lf);
			fwrite(&a11, sizeof(int), 1, lf);
			fclose(lf);

			/* Write global variables into temp file */
			gf = fopen(gb_name, "w");
			fclose(gf);

			/* Call to display the html */
			html_Input(url, sessionid);
			exit(0);

step_1:

			/* Read local variables from temp file */
			lf = fopen(sessionid, "r");
			fgetc(lf);
			fread(&a32, sizeof(int), 1, lf);
			fread(&reset, sizeof(int), 1, lf);
			fread(&a33, sizeof(int), 1, lf);
			fread(&a13, sizeof(int), 1, lf);
			fread(&a31, sizeof(int), 1, lf);
			fread(&a21, sizeof(int), 1, lf);
			fread(&a23, sizeof(int), 1, lf);
			fread(&a22, sizeof(int), 1, lf);
			{
				int tmpi;
				fread(&tmpi, sizeof(int), 1, lf);
				from = (char *)malloc(tmpi+1);
				fread(from, sizeof(char), tmpi, lf);
				from[tmpi] = '\0';
			}
			fread(&a12, sizeof(int), 1, lf);
			fread(&tra, sizeof(int), 1, lf);
			fread(&quit, sizeof(int), 1, lf);
			fread(&det, sizeof(int), 1, lf);
			fread(&a11, sizeof(int), 1, lf);
			fclose(lf);

			/* Read global variables from temp file */
			gf = fopen(gb_name, "r");
			fclose(gf);

			a11 = atoi(getField("a11"));
			a12 = atoi(getField("a12"));
			a13 = atoi(getField("a13"));
			a21 = atoi(getField("a21"));
			a22 = atoi(getField("a22"));
			a23 = atoi(getField("a23"));
			a31 = atoi(getField("a31"));
			a32 = atoi(getField("a32"));
			a33 = atoi(getField("a33"));
			copyString(&from, getField("from"));
			quit = atoi(getField("quit"));
			reset = 0;
		}
		else
		{

			if((strcmp(from,"det")==0))
			{
				det = a11*a22*a33+a12*a23*a31+a13*a21*a32-a13*a22*a31-a12*a21*a33-a11*a23*a32;
				
				/* Write local variables into temp file */
				lf = fopen(sessionid, "w");
				fputc(2, lf);
				fwrite(&a32, sizeof(int), 1, lf);
				fwrite(&reset, sizeof(int), 1, lf);
				fwrite(&a33, sizeof(int), 1, lf);
				fwrite(&a13, sizeof(int), 1, lf);
				fwrite(&a31, sizeof(int), 1, lf);
				fwrite(&a21, sizeof(int), 1, lf);
				fwrite(&a23, sizeof(int), 1, lf);
				fwrite(&a22, sizeof(int), 1, lf);
				{
					int tmpi;
					tmpi = strlen(from);
					fwrite(&tmpi, sizeof(int), 1, lf);
					fwrite(from, sizeof(char), strlen(from), lf);
				}
				fwrite(&a12, sizeof(int), 1, lf);
				fwrite(&tra, sizeof(int), 1, lf);
				fwrite(&quit, sizeof(int), 1, lf);
				fwrite(&det, sizeof(int), 1, lf);
				fwrite(&a11, sizeof(int), 1, lf);
				fclose(lf);

				/* Write global variables into temp file */
				gf = fopen(gb_name, "w");
				fclose(gf);

				/* Call to display the html */
				html_Det(url, sessionid, itoa(a11), itoa(a12), itoa(a13), itoa(a21), itoa(a22), itoa(a23), itoa(a31), itoa(a32), itoa(a33), itoa(det));
				exit(0);

step_2:

				/* Read local variables from temp file */
				lf = fopen(sessionid, "r");
				fgetc(lf);
				fread(&a32, sizeof(int), 1, lf);
				fread(&reset, sizeof(int), 1, lf);
				fread(&a33, sizeof(int), 1, lf);
				fread(&a13, sizeof(int), 1, lf);
				fread(&a31, sizeof(int), 1, lf);
				fread(&a21, sizeof(int), 1, lf);
				fread(&a23, sizeof(int), 1, lf);
				fread(&a22, sizeof(int), 1, lf);
				{
					int tmpi;
					fread(&tmpi, sizeof(int), 1, lf);
					from = (char *)malloc(tmpi+1);
					fread(from, sizeof(char), tmpi, lf);
					from[tmpi] = '\0';
				}
				fread(&a12, sizeof(int), 1, lf);
				fread(&tra, sizeof(int), 1, lf);
				fread(&quit, sizeof(int), 1, lf);
				fread(&det, sizeof(int), 1, lf);
				fread(&a11, sizeof(int), 1, lf);
				fclose(lf);

				/* Read global variables from temp file */
				gf = fopen(gb_name, "r");
				fclose(gf);

				quit = atoi(getField("quit"));
				copyString(&from, getField("from"));
				reset = atoi(getField("reset"));
			}

			if((strcmp(from,"tran")==0))
			{
				
				/* Write local variables into temp file */
				lf = fopen(sessionid, "w");
				fputc(3, lf);
				fwrite(&a32, sizeof(int), 1, lf);
				fwrite(&reset, sizeof(int), 1, lf);
				fwrite(&a33, sizeof(int), 1, lf);
				fwrite(&a13, sizeof(int), 1, lf);
				fwrite(&a31, sizeof(int), 1, lf);
				fwrite(&a21, sizeof(int), 1, lf);
				fwrite(&a23, sizeof(int), 1, lf);
				fwrite(&a22, sizeof(int), 1, lf);
				{
					int tmpi;
					tmpi = strlen(from);
					fwrite(&tmpi, sizeof(int), 1, lf);
					fwrite(from, sizeof(char), strlen(from), lf);
				}
				fwrite(&a12, sizeof(int), 1, lf);
				fwrite(&tra, sizeof(int), 1, lf);
				fwrite(&quit, sizeof(int), 1, lf);
				fwrite(&det, sizeof(int), 1, lf);
				fwrite(&a11, sizeof(int), 1, lf);
				fclose(lf);

				/* Write global variables into temp file */
				gf = fopen(gb_name, "w");
				fclose(gf);

				/* Call to display the html */
				html_Tran(url, sessionid, itoa(a11), itoa(a12), itoa(a13), itoa(a21), itoa(a22), itoa(a23), itoa(a31), itoa(a32), itoa(a33));
				exit(0);

step_3:

				/* Read local variables from temp file */
				lf = fopen(sessionid, "r");
				fgetc(lf);
				fread(&a32, sizeof(int), 1, lf);
				fread(&reset, sizeof(int), 1, lf);
				fread(&a33, sizeof(int), 1, lf);
				fread(&a13, sizeof(int), 1, lf);
				fread(&a31, sizeof(int), 1, lf);
				fread(&a21, sizeof(int), 1, lf);
				fread(&a23, sizeof(int), 1, lf);
				fread(&a22, sizeof(int), 1, lf);
				{
					int tmpi;
					fread(&tmpi, sizeof(int), 1, lf);
					from = (char *)malloc(tmpi+1);
					fread(from, sizeof(char), tmpi, lf);
					from[tmpi] = '\0';
				}
				fread(&a12, sizeof(int), 1, lf);
				fread(&tra, sizeof(int), 1, lf);
				fread(&quit, sizeof(int), 1, lf);
				fread(&det, sizeof(int), 1, lf);
				fread(&a11, sizeof(int), 1, lf);
				fclose(lf);

				/* Read global variables from temp file */
				gf = fopen(gb_name, "r");
				fclose(gf);

				quit = atoi(getField("quit"));
				copyString(&from, getField("from"));
				reset = atoi(getField("reset"));
			}

			if((strcmp(from,"tra")==0))
			{
				tra = a11+a22+a33;
				
				/* Write local variables into temp file */
				lf = fopen(sessionid, "w");
				fputc(4, lf);
				fwrite(&a32, sizeof(int), 1, lf);
				fwrite(&reset, sizeof(int), 1, lf);
				fwrite(&a33, sizeof(int), 1, lf);
				fwrite(&a13, sizeof(int), 1, lf);
				fwrite(&a31, sizeof(int), 1, lf);
				fwrite(&a21, sizeof(int), 1, lf);
				fwrite(&a23, sizeof(int), 1, lf);
				fwrite(&a22, sizeof(int), 1, lf);
				{
					int tmpi;
					tmpi = strlen(from);
					fwrite(&tmpi, sizeof(int), 1, lf);
					fwrite(from, sizeof(char), strlen(from), lf);
				}
				fwrite(&a12, sizeof(int), 1, lf);
				fwrite(&tra, sizeof(int), 1, lf);
				fwrite(&quit, sizeof(int), 1, lf);
				fwrite(&det, sizeof(int), 1, lf);
				fwrite(&a11, sizeof(int), 1, lf);
				fclose(lf);

				/* Write global variables into temp file */
				gf = fopen(gb_name, "w");
				fclose(gf);

				/* Call to display the html */
				html_Tra(url, sessionid, itoa(a11), itoa(a12), itoa(a13), itoa(a21), itoa(a22), itoa(a23), itoa(a31), itoa(a32), itoa(a33), itoa(tra));
				exit(0);

step_4:

				/* Read local variables from temp file */
				lf = fopen(sessionid, "r");
				fgetc(lf);
				fread(&a32, sizeof(int), 1, lf);
				fread(&reset, sizeof(int), 1, lf);
				fread(&a33, sizeof(int), 1, lf);
				fread(&a13, sizeof(int), 1, lf);
				fread(&a31, sizeof(int), 1, lf);
				fread(&a21, sizeof(int), 1, lf);
				fread(&a23, sizeof(int), 1, lf);
				fread(&a22, sizeof(int), 1, lf);
				{
					int tmpi;
					fread(&tmpi, sizeof(int), 1, lf);
					from = (char *)malloc(tmpi+1);
					fread(from, sizeof(char), tmpi, lf);
					from[tmpi] = '\0';
				}
				fread(&a12, sizeof(int), 1, lf);
				fread(&tra, sizeof(int), 1, lf);
				fread(&quit, sizeof(int), 1, lf);
				fread(&det, sizeof(int), 1, lf);
				fread(&a11, sizeof(int), 1, lf);
				fclose(lf);

				/* Read global variables from temp file */
				gf = fopen(gb_name, "r");
				fclose(gf);

				quit = atoi(getField("quit"));
				copyString(&from, getField("from"));
				reset = atoi(getField("reset"));
			}
		}
	}
	
	/* Write local variables into temp file */
	lf = fopen(sessionid, "w");
	fputc(4, lf);
	fwrite(&a32, sizeof(int), 1, lf);
	fwrite(&reset, sizeof(int), 1, lf);
	fwrite(&a33, sizeof(int), 1, lf);
	fwrite(&a13, sizeof(int), 1, lf);
	fwrite(&a31, sizeof(int), 1, lf);
	fwrite(&a21, sizeof(int), 1, lf);
	fwrite(&a23, sizeof(int), 1, lf);
	fwrite(&a22, sizeof(int), 1, lf);
	{
		int tmpi;
		tmpi = strlen(from);
		fwrite(&tmpi, sizeof(int), 1, lf);
		fwrite(from, sizeof(char), strlen(from), lf);
	}
	fwrite(&a12, sizeof(int), 1, lf);
	fwrite(&tra, sizeof(int), 1, lf);
	fwrite(&quit, sizeof(int), 1, lf);
	fwrite(&det, sizeof(int), 1, lf);
	fwrite(&a11, sizeof(int), 1, lf);
	fclose(lf);

	/* Write global variables into temp file */
	gf = fopen(gb_name, "w");
	fclose(gf);

	/* We remove session id before exiting */
	remove(sessionid);
	sessionid = "";

	/* Call to display the html */
	html_Finish(url, sessionid);
	exit(0);

}

/* Main function section */

int main (int argc, char *agrv[])
{
	/* Initialize random seed */
	srand48(time((time_t *)0));

	/* Parse fields */
	parseFields();
	url = catString("http://", catString(getenv("SERVER_NAME"), getenv("SCRIPT_NAME")));
	sessionid = getenv("QUERY_STRING");

	/* Decide which service to launch */
	if (sessionid == NULL) goto error_and_exit;

	if (strcmp(sessionid,"Start") == 0) session_Start(0);
	if (strncmp(sessionid,"Start$",6) == 0) session_Start(1);

/* Display the error page if an invalid sessionid is passed */
error_and_exit:
	printf("Content-type: text/html\n\n");
	printf("<html><body>\n");
	printf("<h3>Sorry, your session has expired or is not valid.</h3>\n");
	printf("<h3>Valid session(s) are:</h3>\n");
	printf("   --> Start<br>");
	printf("<br>Example: <b><i>%s?Start</i></b>\n", getenv("SCRIPT_NAME"));
	printf("</body></html>\n");
	exit(1);
}
