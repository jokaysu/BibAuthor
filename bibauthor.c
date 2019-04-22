static char sqla_program_id[292] = 
{
 172,0,65,69,65,85,65,73,70,66,74,122,76,101,75,104,48,49,49,49,
 49,32,50,32,32,32,32,32,32,32,32,32,8,0,67,50,56,83,85,32,
 32,32,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,8,0,66,73,66,65,85,84,72,79,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0
};

#include "sqladef.h"

static struct sqla_runtime_info sqla_rtinfo = 
{{'S','Q','L','A','R','T','I','N'}, sizeof(wchar_t), 0, {' ',' ',' ',' '}};


static const short sqlIsLiteral   = SQL_IS_LITERAL;
static const short sqlIsInputHvar = SQL_IS_INPUT_HVAR;


#line 1 "bibauthor.sqc"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"



/*
EXEC SQL INCLUDE SQLCA;
*/

/* SQL Communication Area - SQLCA - structures and constants */
#include "sqlca.h"
struct sqlca sqlca;


#line 7 "bibauthor.sqc"
 


/*
EXEC SQL BEGIN DECLARE SECTION;
*/

#line 9 "bibauthor.sqc"

   	char db[6] = "cs348";
   	char name[22];
   	char theauthor[22];
   	char pubid[10], title[70];
   	char publisher[50];
   	sqlint32 year;
   	sqlint32 volume, number;
   	sqlint32 startpage, endpage;
   	char appearsin[10];

/*
EXEC SQL END DECLARE SECTION;
*/

#line 19 "bibauthor.sqc"


int main(int argc, char *argv[]) {
    if (argc!=2) {
       printf("Usage: bibauthor <pattern>\n");
       exit(1);
    };
    //printf("Author is %s\n", argv[1]);

    
/*
EXEC SQL WHENEVER SQLERROR GO TO error;
*/

#line 28 "bibauthor.sqc"


    
/*
EXEC SQL CONNECT TO :db;
*/

{
#line 30 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 30 "bibauthor.sqc"
  sqlaaloc(2,1,1,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 30 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 6;
#line 30 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)db;
#line 30 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 30 "bibauthor.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 30 "bibauthor.sqc"
  sqlacall((unsigned short)29,4,2,0,0L);
#line 30 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 30 "bibauthor.sqc"
  sqlastop(0L);
}

#line 30 "bibauthor.sqc"


    strncpy(theauthor, argv[1], 22);
    int n = 0;
    char **printed = malloc(22 * n * sizeof(char));

    //books
    printf("book seraching\n");
    
/*
EXEC SQL DECLARE pubs CURSOR FOR
    		 SELECT publication.pubid, publication.title, book.publisher, book.year
    		 FROM author, wrote, publication, book
    		 WHERE name LIKE :theauthor
    		   AND wrote.aid=author.aid
    		   AND wrote.pubid=publication.pubid
    		   AND publication.pubid=book.pubid;
*/

#line 44 "bibauthor.sqc"


    
/*
EXEC SQL OPEN pubs;
*/

{
#line 46 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 46 "bibauthor.sqc"
  sqlaaloc(2,1,2,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 46 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 22;
#line 46 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)theauthor;
#line 46 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 46 "bibauthor.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 46 "bibauthor.sqc"
  sqlacall((unsigned short)26,1,2,0,0L);
#line 46 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 46 "bibauthor.sqc"
  sqlastop(0L);
}

#line 46 "bibauthor.sqc"

    for(;;) {
    	
/*
EXEC SQL WHENEVER NOT FOUND GO TO notfound1;
*/

#line 48 "bibauthor.sqc"

    	
/*
EXEC SQL FETCH pubs INTO :pubid, :title, :publisher, :year;
*/

{
#line 49 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 49 "bibauthor.sqc"
  sqlaaloc(3,4,3,0L);
    {
      struct sqla_setdata_list sql_setdlist[4];
#line 49 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 10;
#line 49 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 49 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 49 "bibauthor.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 70;
#line 49 "bibauthor.sqc"
      sql_setdlist[1].sqldata = (void*)title;
#line 49 "bibauthor.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 49 "bibauthor.sqc"
      sql_setdlist[2].sqltype = 460; sql_setdlist[2].sqllen = 50;
#line 49 "bibauthor.sqc"
      sql_setdlist[2].sqldata = (void*)publisher;
#line 49 "bibauthor.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 49 "bibauthor.sqc"
      sql_setdlist[3].sqltype = 496; sql_setdlist[3].sqllen = 4;
#line 49 "bibauthor.sqc"
      sql_setdlist[3].sqldata = (void*)&year;
#line 49 "bibauthor.sqc"
      sql_setdlist[3].sqlind = 0L;
#line 49 "bibauthor.sqc"
      sqlasetdata(3,0,4,sql_setdlist,0L,0L);
    }
#line 49 "bibauthor.sqc"
  sqlacall((unsigned short)25,1,0,3,0L);
#line 49 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 49 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto notfound1;
  }
#line 49 "bibauthor.sqc"
  sqlastop(0L);
}

#line 49 "bibauthor.sqc"

    	printf("Pubid:  %s\n", pubid);
    	printf("Type:  book\n");
    	printf("Title:  %s\n", title);
    	printf("Authors:  ");

    	
/*
EXEC SQL DECLARE author CURSOR FOR
    			SELECT author.name
    			FROM author, wrote
    			WHERE author.aid=wrote.aid
    			  AND wrote.pubid=:pubid;
*/

#line 59 "bibauthor.sqc"

    	
/*
EXEC SQL OPEN author;
*/

{
#line 60 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 60 "bibauthor.sqc"
  sqlaaloc(2,1,4,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 60 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 10;
#line 60 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 60 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 60 "bibauthor.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 60 "bibauthor.sqc"
  sqlacall((unsigned short)26,2,2,0,0L);
#line 60 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 60 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto notfound1;
  }
#line 60 "bibauthor.sqc"
  sqlastop(0L);
}

#line 60 "bibauthor.sqc"

    	for (;;) {
    		
/*
EXEC SQL FETCH author INTO :name;
*/

{
#line 62 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 62 "bibauthor.sqc"
  sqlaaloc(3,1,5,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 62 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 22;
#line 62 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)name;
#line 62 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 62 "bibauthor.sqc"
      sqlasetdata(3,0,1,sql_setdlist,0L,0L);
    }
#line 62 "bibauthor.sqc"
  sqlacall((unsigned short)25,2,0,3,0L);
#line 62 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 62 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto notfound1;
  }
#line 62 "bibauthor.sqc"
  sqlastop(0L);
}

#line 62 "bibauthor.sqc"

    		printf("%s, ", name);
    	};
    	
/*
EXEC SQL CLOSE author;
*/

{
#line 65 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 65 "bibauthor.sqc"
  sqlacall((unsigned short)20,2,0,0,0L);
#line 65 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 65 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto notfound1;
  }
#line 65 "bibauthor.sqc"
  sqlastop(0L);
}

#line 65 "bibauthor.sqc"

    	printf("\n");
    	printf("Publisher:  %s\n", publisher);
    	printf("Year:  %d\n", year);
    }
notfound1:
    
/*
EXEC SQL CLOSE pubs;
*/

{
#line 71 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 71 "bibauthor.sqc"
  sqlacall((unsigned short)20,1,0,0,0L);
#line 71 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 71 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto notfound1;
  }
#line 71 "bibauthor.sqc"
  sqlastop(0L);
}

#line 71 "bibauthor.sqc"

    

    //journals
    printf("journal searching\n");
    
/*
EXEC SQL DECLARE pubs2 CURSOR FOR
    		 SELECT publication.pubid, publication.title, journal.volume, journal.number, journal.year
    		 FROM author, wrote, publication, journal
    		 WHERE name LIKE :theauthor
    		   AND wrote.aid=author.aid
    		   AND wrote.pubid=publication.pubid
    		   AND journal.pubid=publication.pubid;
*/

#line 82 "bibauthor.sqc"


    
/*
EXEC SQL OPEN pubs;
*/

{
#line 84 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 84 "bibauthor.sqc"
  sqlaaloc(2,1,6,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 84 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 22;
#line 84 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)theauthor;
#line 84 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 84 "bibauthor.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 84 "bibauthor.sqc"
  sqlacall((unsigned short)26,1,2,0,0L);
#line 84 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 84 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto notfound1;
  }
#line 84 "bibauthor.sqc"
  sqlastop(0L);
}

#line 84 "bibauthor.sqc"

    for(;;) {
    	
/*
EXEC SQL WHENEVER NOT FOUND GO TO notfound2;
*/

#line 86 "bibauthor.sqc"

    	
/*
EXEC SQL FETCH pubs2 INTO :pubid, :title, :volume, :number, :year;
*/

{
#line 87 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 87 "bibauthor.sqc"
  sqlaaloc(3,5,7,0L);
    {
      struct sqla_setdata_list sql_setdlist[5];
#line 87 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 10;
#line 87 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 87 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 87 "bibauthor.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 70;
#line 87 "bibauthor.sqc"
      sql_setdlist[1].sqldata = (void*)title;
#line 87 "bibauthor.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 87 "bibauthor.sqc"
      sql_setdlist[2].sqltype = 496; sql_setdlist[2].sqllen = 4;
#line 87 "bibauthor.sqc"
      sql_setdlist[2].sqldata = (void*)&volume;
#line 87 "bibauthor.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 87 "bibauthor.sqc"
      sql_setdlist[3].sqltype = 496; sql_setdlist[3].sqllen = 4;
#line 87 "bibauthor.sqc"
      sql_setdlist[3].sqldata = (void*)&number;
#line 87 "bibauthor.sqc"
      sql_setdlist[3].sqlind = 0L;
#line 87 "bibauthor.sqc"
      sql_setdlist[4].sqltype = 496; sql_setdlist[4].sqllen = 4;
#line 87 "bibauthor.sqc"
      sql_setdlist[4].sqldata = (void*)&year;
#line 87 "bibauthor.sqc"
      sql_setdlist[4].sqlind = 0L;
#line 87 "bibauthor.sqc"
      sqlasetdata(3,0,5,sql_setdlist,0L,0L);
    }
#line 87 "bibauthor.sqc"
  sqlacall((unsigned short)25,3,0,3,0L);
#line 87 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 87 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto notfound2;
  }
#line 87 "bibauthor.sqc"
  sqlastop(0L);
}

#line 87 "bibauthor.sqc"

    	printf("Pubid:  %s\n", pubid);
    	printf("Type:  journal\n");
    	printf("Title:  %s\n", title);
    	printf("Volume:  %d\n", volume);
    	printf("Number:  %d\n", number);
    	printf("Year:  %d\n", year);
    }
notfound2:
    
/*
EXEC SQL CLOSE pubs2;
*/

{
#line 96 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 96 "bibauthor.sqc"
  sqlacall((unsigned short)20,3,0,0,0L);
#line 96 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 96 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto notfound2;
  }
#line 96 "bibauthor.sqc"
  sqlastop(0L);
}

#line 96 "bibauthor.sqc"


    //proceedings
    printf("proceedings searching\n");
    
/*
EXEC SQL DECLARE pubs3 CURSOR FOR
    		 SELECT publication.pubid, publication.title, year
    		 FROM author, wrote, publication, proceedings
    		 WHERE name LIKE :theauthor
    		   AND wrote.aid=author.aid
    		   AND wrote.pubid=publication.pubid
    		   AND publication.pubid=proceedings.pubid;
*/

#line 106 "bibauthor.sqc"


    
/*
EXEC SQL OPEN pubs3;
*/

{
#line 108 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 108 "bibauthor.sqc"
  sqlaaloc(2,1,8,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 108 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 22;
#line 108 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)theauthor;
#line 108 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 108 "bibauthor.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 108 "bibauthor.sqc"
  sqlacall((unsigned short)26,4,2,0,0L);
#line 108 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 108 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto notfound2;
  }
#line 108 "bibauthor.sqc"
  sqlastop(0L);
}

#line 108 "bibauthor.sqc"

    for(;;) {
    	
/*
EXEC SQL WHENEVER NOT FOUND GO TO notfound3;
*/

#line 110 "bibauthor.sqc"

    	
/*
EXEC SQL FETCH pubs INTO :pubid, :title, :year;
*/

{
#line 111 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 111 "bibauthor.sqc"
  sqlaaloc(3,3,9,0L);
    {
      struct sqla_setdata_list sql_setdlist[3];
#line 111 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 10;
#line 111 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 111 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 111 "bibauthor.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 70;
#line 111 "bibauthor.sqc"
      sql_setdlist[1].sqldata = (void*)title;
#line 111 "bibauthor.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 111 "bibauthor.sqc"
      sql_setdlist[2].sqltype = 496; sql_setdlist[2].sqllen = 4;
#line 111 "bibauthor.sqc"
      sql_setdlist[2].sqldata = (void*)&year;
#line 111 "bibauthor.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 111 "bibauthor.sqc"
      sqlasetdata(3,0,3,sql_setdlist,0L,0L);
    }
#line 111 "bibauthor.sqc"
  sqlacall((unsigned short)25,1,0,3,0L);
#line 111 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 111 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto notfound3;
  }
#line 111 "bibauthor.sqc"
  sqlastop(0L);
}

#line 111 "bibauthor.sqc"

    	printf("Pubid:  %s\n", pubid);
    	printf("Type:  proceedings\n");
    	printf("Title:  %s\n", title);
    	printf("Year:  %d\n", year);
    }
notfound3:
    
/*
EXEC SQL CLOSE pubs3;
*/

{
#line 118 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 118 "bibauthor.sqc"
  sqlacall((unsigned short)20,4,0,0,0L);
#line 118 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 118 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto notfound3;
  }
#line 118 "bibauthor.sqc"
  sqlastop(0L);
}

#line 118 "bibauthor.sqc"


    //article
    printf("article searching\n");
    
/*
EXEC SQL DECLARE pubs4 CURSOR FOR
    		 SELECT publication.pubid, publication.title, article.appearsin, article.startpage, article.endpage
    		 FROM author, wrote, publication, article
    		 WHERE name LIKE :theauthor
    		   AND wrote.aid=author.aid
    		   AND wrote.pubid=publication.pubid
    		   AND publication.pubid=article.pubid;
*/

#line 128 "bibauthor.sqc"


    
/*
EXEC SQL OPEN pubs4;
*/

{
#line 130 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 130 "bibauthor.sqc"
  sqlaaloc(2,1,10,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 130 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 22;
#line 130 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)theauthor;
#line 130 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 130 "bibauthor.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 130 "bibauthor.sqc"
  sqlacall((unsigned short)26,5,2,0,0L);
#line 130 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 130 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto notfound3;
  }
#line 130 "bibauthor.sqc"
  sqlastop(0L);
}

#line 130 "bibauthor.sqc"

    for(;;) {
    	
/*
EXEC SQL WHENEVER NOT FOUND GO TO notfound4;
*/

#line 132 "bibauthor.sqc"

    	
/*
EXEC SQL FETCH pubs4 INTO :pubid, :title, :appearsin, :startpage, :endpage;
*/

{
#line 133 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 133 "bibauthor.sqc"
  sqlaaloc(3,5,11,0L);
    {
      struct sqla_setdata_list sql_setdlist[5];
#line 133 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 10;
#line 133 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 133 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 133 "bibauthor.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 70;
#line 133 "bibauthor.sqc"
      sql_setdlist[1].sqldata = (void*)title;
#line 133 "bibauthor.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 133 "bibauthor.sqc"
      sql_setdlist[2].sqltype = 460; sql_setdlist[2].sqllen = 10;
#line 133 "bibauthor.sqc"
      sql_setdlist[2].sqldata = (void*)appearsin;
#line 133 "bibauthor.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 133 "bibauthor.sqc"
      sql_setdlist[3].sqltype = 496; sql_setdlist[3].sqllen = 4;
#line 133 "bibauthor.sqc"
      sql_setdlist[3].sqldata = (void*)&startpage;
#line 133 "bibauthor.sqc"
      sql_setdlist[3].sqlind = 0L;
#line 133 "bibauthor.sqc"
      sql_setdlist[4].sqltype = 496; sql_setdlist[4].sqllen = 4;
#line 133 "bibauthor.sqc"
      sql_setdlist[4].sqldata = (void*)&endpage;
#line 133 "bibauthor.sqc"
      sql_setdlist[4].sqlind = 0L;
#line 133 "bibauthor.sqc"
      sqlasetdata(3,0,5,sql_setdlist,0L,0L);
    }
#line 133 "bibauthor.sqc"
  sqlacall((unsigned short)25,5,0,3,0L);
#line 133 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 133 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto notfound4;
  }
#line 133 "bibauthor.sqc"
  sqlastop(0L);
}

#line 133 "bibauthor.sqc"

    	printf("Pubid:  %s\n", pubid);
    	printf("Type:  article\n");
    	printf("Title:  %s\n", title);
    	printf("Authors:  ");

    	
/*
EXEC SQL DECLARE author2 CURSOR FOR    	
    			SELECT name
    			FROM author, wrote
    			WHERE wrote.aid=author.aid
    			AND pubid=:pubid;
*/

#line 143 "bibauthor.sqc"

    	
/*
EXEC SQL OPEN author2;
*/

{
#line 144 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 144 "bibauthor.sqc"
  sqlaaloc(2,1,12,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 144 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 10;
#line 144 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 144 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 144 "bibauthor.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 144 "bibauthor.sqc"
  sqlacall((unsigned short)26,6,2,0,0L);
#line 144 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 144 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto notfound4;
  }
#line 144 "bibauthor.sqc"
  sqlastop(0L);
}

#line 144 "bibauthor.sqc"

    	for (;;) {
    		
/*
EXEC SQL FETCH author INTO :name;
*/

{
#line 146 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 146 "bibauthor.sqc"
  sqlaaloc(3,1,13,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 146 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 22;
#line 146 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)name;
#line 146 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 146 "bibauthor.sqc"
      sqlasetdata(3,0,1,sql_setdlist,0L,0L);
    }
#line 146 "bibauthor.sqc"
  sqlacall((unsigned short)25,2,0,3,0L);
#line 146 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 146 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto notfound4;
  }
#line 146 "bibauthor.sqc"
  sqlastop(0L);
}

#line 146 "bibauthor.sqc"

    		printf("%s, ", name);
    	};
    	
/*
EXEC SQL CLOSE author2;
*/

{
#line 149 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 149 "bibauthor.sqc"
  sqlacall((unsigned short)20,6,0,0,0L);
#line 149 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 149 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto notfound4;
  }
#line 149 "bibauthor.sqc"
  sqlastop(0L);
}

#line 149 "bibauthor.sqc"

    	printf("\n");
    	printf("In:  %s\n", appearsin);
    	printf("Pages:  %d--%d\n", startpage, endpage);
    }
notfound4:
    
/*
EXEC SQL CLOSE pubs4;
*/

{
#line 155 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 155 "bibauthor.sqc"
  sqlacall((unsigned short)20,5,0,0,0L);
#line 155 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 155 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto notfound4;
  }
#line 155 "bibauthor.sqc"
  sqlastop(0L);
}

#line 155 "bibauthor.sqc"


    //normal ending
    
/*
EXEC SQL COMMIT;
*/

{
#line 158 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 158 "bibauthor.sqc"
  sqlacall((unsigned short)21,0,0,0,0L);
#line 158 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 158 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto notfound4;
  }
#line 158 "bibauthor.sqc"
  sqlastop(0L);
}

#line 158 "bibauthor.sqc"

    
/*
EXEC SQL CONNECT RESET;
*/

{
#line 159 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 159 "bibauthor.sqc"
  sqlacall((unsigned short)29,3,0,0,0L);
#line 159 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 159 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto notfound4;
  }
#line 159 "bibauthor.sqc"
  sqlastop(0L);
}

#line 159 "bibauthor.sqc"

    exit(0);

notfound:
	
/*
EXEC SQL CLOSE author;
*/

{
#line 163 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 163 "bibauthor.sqc"
  sqlacall((unsigned short)20,2,0,0,0L);
#line 163 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 163 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto notfound4;
  }
#line 163 "bibauthor.sqc"
  sqlastop(0L);
}

#line 163 "bibauthor.sqc"

	
/*
EXEC SQL CLOSE author2;
*/

{
#line 164 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 164 "bibauthor.sqc"
  sqlacall((unsigned short)20,6,0,0,0L);
#line 164 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 164 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto notfound4;
  }
#line 164 "bibauthor.sqc"
  sqlastop(0L);
}

#line 164 "bibauthor.sqc"

	
/*
EXEC SQL CLOSE pubs;
*/

{
#line 165 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 165 "bibauthor.sqc"
  sqlacall((unsigned short)20,1,0,0,0L);
#line 165 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 165 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto notfound4;
  }
#line 165 "bibauthor.sqc"
  sqlastop(0L);
}

#line 165 "bibauthor.sqc"

	
/*
EXEC SQL CLOSE pubs2;
*/

{
#line 166 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 166 "bibauthor.sqc"
  sqlacall((unsigned short)20,3,0,0,0L);
#line 166 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 166 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto notfound4;
  }
#line 166 "bibauthor.sqc"
  sqlastop(0L);
}

#line 166 "bibauthor.sqc"

	
/*
EXEC SQL CLOSE pubs3;
*/

{
#line 167 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 167 "bibauthor.sqc"
  sqlacall((unsigned short)20,4,0,0,0L);
#line 167 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 167 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto notfound4;
  }
#line 167 "bibauthor.sqc"
  sqlastop(0L);
}

#line 167 "bibauthor.sqc"

	
/*
EXEC SQL CLOSE pubs4;
*/

{
#line 168 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 168 "bibauthor.sqc"
  sqlacall((unsigned short)20,5,0,0,0L);
#line 168 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 168 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto notfound4;
  }
#line 168 "bibauthor.sqc"
  sqlastop(0L);
}

#line 168 "bibauthor.sqc"

	
/*
EXEC SQL COMMIT;
*/

{
#line 169 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 169 "bibauthor.sqc"
  sqlacall((unsigned short)21,0,0,0,0L);
#line 169 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 169 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto notfound4;
  }
#line 169 "bibauthor.sqc"
  sqlastop(0L);
}

#line 169 "bibauthor.sqc"

	
/*
EXEC SQL CONNECT RESET;
*/

{
#line 170 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 170 "bibauthor.sqc"
  sqlacall((unsigned short)29,3,0,0,0L);
#line 170 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 170 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto notfound4;
  }
#line 170 "bibauthor.sqc"
  sqlastop(0L);
}

#line 170 "bibauthor.sqc"

	exit(0);

error:
	
/*
EXEC SQL WHENEVER SQLERROR CONTINUE;
*/

#line 174 "bibauthor.sqc"

	
/*
EXEC SQL ROLLBACK;
*/

{
#line 175 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 175 "bibauthor.sqc"
  sqlacall((unsigned short)28,0,0,0,0L);
#line 175 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto notfound4;
  }
#line 175 "bibauthor.sqc"
  sqlastop(0L);
}

#line 175 "bibauthor.sqc"

	
/*
EXEC SQL CONNECT reset;
*/

{
#line 176 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 176 "bibauthor.sqc"
  sqlacall((unsigned short)29,3,0,0,0L);
#line 176 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto notfound4;
  }
#line 176 "bibauthor.sqc"
  sqlastop(0L);
}

#line 176 "bibauthor.sqc"

	exit(1);
}
