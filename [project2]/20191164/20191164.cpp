#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>

#include "mysql.h"
using namespace std;

#pragma comment(lib, "libmysql.lib")

const char* host = "localhost";
const char* user = "root";
const char* pw = "asdf1234";
const char* db = "project2";

int main(void) {

	MYSQL* connection = NULL;
	MYSQL conn;
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	if (mysql_init(&conn) == NULL)
		printf("mysql_init() error!");

	connection = mysql_real_connect(&conn, host, user, pw, db, 3306, (const char*)NULL, 0);
	if (connection == NULL)
	{
		printf("%d ERROR : %s\n", mysql_errno(&conn), mysql_error(&conn));
		return 1;
	}

    else
    {
        printf("Connection Succeed\n");


        if (mysql_select_db(&conn, db))
        {
            printf("%d ERROR : %s\n", mysql_errno(&conn), mysql_error(&conn));
            return 1;
        }


        
        /////////
        const char* query;
        const char* query22 = NULL;
        FILE* input_fp = fopen("20191164.txt", "r");
        if (input_fp == NULL) {
            fprintf(stderr, "file open error");
        }
        else {
            char str[2048];
           // char query;
            while (!feof(input_fp)) {
                query = fgets(str, sizeof(str), input_fp);
                mysql_query(connection, query);
            }
        }
        fclose(input_fp);


        while (1) {
            /*
            const char* query0 = "select * from package";
            int state0 = 0;

            state0 = mysql_query(connection, query0);
            if (state0 == 0)
            {
                sql_result = mysql_store_result(connection);
                while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
                {
                    printf("%s \n", sql_row[0]);
                }
                mysql_free_result(sql_result);
            }
            */

            printf("------- SELECT QUERY TYPES -------\n\n");
            printf("\t1. TYPE 1\n");
            printf("\t2. TYPE 2\n");
            printf("\t3. TYPE 3\n");
            printf("\t4. TYPE 4\n");
            printf("\t5. TYPE 5\n");
            printf("\t0. QUIT\n");
            printf("\n\n");

            int type;
            cin >> type;


            if (type == 1) {
                cout << "---- TYPE 1 ----\n\n";

                while (1) {
                    cout << "Serial Number of truck?: ";
                    string truck;
                    cin >> truck;
                    if (truck == "0") {
                        cout << "TYPE 1 Quit\n";
                        break;
                    
                    }

                    printf("\n------- Subtypes in TYPE 1 -------\n\n");
                    printf("\t1. TYPE 1-1.\n");
                    printf("\t2. TYPE 1-2.\n");
                    printf("\t3. TYPE 1-3.\n");

                    while (1) {
                        int subtype;
                        cin >> subtype;

                        if (subtype == 1) {
                            
                            cout << "---- TYPE 1-1. ----\n\n";
                            cout << "** Find all customers who had a package on the truck at the time of the crash. **\n";

                            cout << printf("Customer ID: ");
    //                        int c_id_1_1;
    //                        cin >> c_id_1_1;
                            string query1_1 = "select P.package_id from tracking T, shipment S, package P where P.shipment_id = S.shipment_id and T.shipment_id = S.shipment_id and T.tracked_time = (select MAX(tracked_time) from tracking) and T.vehicle_type = 'truck' and T.serial_number = '";
                           
                            query1_1 = query1_1 + truck + "'";
                            //cout << "\n -- query: " << query1_1 <<"\n\n";

                            char ch_query1_1[256];
                            strcpy(ch_query1_1, query1_1.c_str());

                            int state1_1 = 0;

                            state1_1 = mysql_query(connection, ch_query1_1);
                            if (state1_1 == 0)
                            {
                                sql_result = mysql_store_result(connection);
                                while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
                                {
                                    printf("%s | ", sql_row[0]);
                                }
                                mysql_free_result(sql_result);
                            }
                            printf("\n\n");
                            
                            continue;
                        }

                        

                        else if (subtype == 2) {
                            cout << "---- TYPE 1-2. ----\n\n";
                            cout << "** Find all recipients who had a package on the truck at the time of the crash. **\n";
                            cout << "Customer name: ";

                            string query1_2 = "select S.recipient_name from tracking T, shipment S where T.shipment_id = S.shipment_id and T.tracked_time = (select MAX(tracked_time) from tracking) and T.vehicle_type = 'truck' and T.serial_number = '";
                            query1_2 = query1_2 + truck + "'";

                            char ch_query1_2[256];
                            strcpy(ch_query1_2, query1_2.c_str());


                            //cout << "\n -- query: " << query1_2 << "\n\n";

                            int state1_2 = 0;
                            state1_2 = mysql_query(connection, ch_query1_2);
                            if (state1_2 == 0)
                            {
                                sql_result = mysql_store_result(connection);
                                while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
                                {
                                    printf("%s | ", sql_row[0]);
                                }
                                mysql_free_result(sql_result);
                            }
                            printf("\n\n");
                            continue;
                        }

                        else if (subtype == 3) {
                            cout << "---- TYPE 1-3. ----\n\n";
                            cout << "** Find the last successful delivery by that truck prior to the crash. **\n";
                            cout << "Last Successful Delivery on: ";

                            string query1_3 = "select * from tracking where tracked_time = (select MAX(tracked_time) from tracking) and vehicle_type = 'truck' and serial_number = '";
                            query1_3 = query1_3 + truck + "'";
                            //cout << "\n -- query: " << query1_3 << "\n\n";
                            char ch_query1_3[256];
                            strcpy(ch_query1_3, query1_3.c_str());
                            printf("%10s | %10s | %10s | %10s\n", "tracking_id", "status", "tracked_time", "shipment_id");
                            int state1_3 = 0;
                            state1_3 = mysql_query(connection, ch_query1_3);
                            if (state1_3 == 0)
                            {
                                sql_result = mysql_store_result(connection);
                                while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
                                {
                                    printf("%10s | %10s | %10s | %10s\n", sql_row[0], sql_row[1], sql_row[2], sql_row[3]);
                                    //printf("%s | ", sql_row[0]);
                                }
                                mysql_free_result(sql_result);
                            }
                            printf("\n\n");
                            continue;

                        }

                        else if (subtype == 0) {
                            cout << "Reenter truck number \n\n";
                            break;
                        }

                        else {
                            cout << "Choose number between 1-3\n";
                            continue;
                        }
                    }
                }


            }
            /*

            else if (type == 10) {
                const char* query_temp = "select *";
                int state1010 = 0;

                state1010 = mysql_query(connection, query_temp);
                if (state1010 == 0)
                {
                    sql_result = mysql_store_result(connection);
                    while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
                    {
                        printf("%s %s %s %s\n", sql_row[0], sql_row[1], sql_row[2], sql_row[3]);
                    }
                    mysql_free_result(sql_result);
                }

                mysql_close(connection);
             }

             */

            else if (type == 2) {
                while (1) {
                    cout << "---- TYPE 2 ----\n\n";
                    printf("** Find the customer who has shipped the most packages in certain year**\n");
                    printf(" Which year? : \n");
                    string year;
                    cin >> year;
                    if (year == "0") {
                        cout << "QUIT Type 2\n";
                        break;
                    }
                    cout << "Customer ID: ";
                    

                    string query2 = "select customer_id from customer where last_year_frequency = (select MAX(last_year_frequency) from customer)";

                   // cout << "\n -- query: " << query2 << "\n\n";

                    char ch_query2[256];
                    strcpy(ch_query2, query2.c_str());

                    int state2 = 0;
                    state2 = mysql_query(connection, ch_query2);
                    if (state2 == 0)
                    {
                        sql_result = mysql_store_result(connection);
                        while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
                        {
                            printf("%s | ", sql_row[0]);
                        }
                        mysql_free_result(sql_result);
                    }
                    printf("\n\n");

                    continue;
                }


            }

            else if (type == 3) {

                while (1) {
                    cout << "---- TYPE 3 ----\n\n";
                    printf("** Find the customer who has spent the most money on shipping in the past year**\n");
                    printf(" Which year? : \n");
                    string year;
                    cin >> year;
                    if (year == "0") {
                        cout << "Quit type 3\n";
                        break;
                    }

                    cout << "Customer ID: ";
                    
                    string query3 = "select customer_id from customer where last_year_total_charge = (select MAX(last_year_total_charge) from customer)";

                    //cout << "\n -- query: " << query3 << "\n\n";
                    char ch_query3[256];
                    strcpy(ch_query3, query3.c_str());

                    int state3 = 0;
                    state3 = mysql_query(connection, ch_query3);
                    if (state3 == 0)
                    {
                        sql_result = mysql_store_result(connection);
                        while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
                        {
                            printf("%s | ", sql_row[0]);
                        }
                        mysql_free_result(sql_result);
                    }
                    printf("\n\n");

                    continue;
                }
            }

            else if (type == 4) {
                cout << "---- TYPE 4 ----\n\n";
                printf("** Find the packages that were not delivered within the promised time.**\n");

                string query4 = "select package_id from package P, shipment S where P.shipment_id = S.shipment_id and S.delivered_time>S.promised_time";

                //cout << "\n -- query: " << query4 << "\n\n";
                char ch_query4[256];
                strcpy(ch_query4, query4.c_str());

                int state4 = 0;
                state4 = mysql_query(connection, ch_query4);
                if (state4 == 0)
                {
                    sql_result = mysql_store_result(connection);
                    while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
                    {
                        printf("%s | ", sql_row[0]);
                    }
                    mysql_free_result(sql_result);
                }
                printf("\n\n");

                continue;

            }

            else if (type == 5) {
                while (1) {
                    printf("---- TYPE 5 ----\n\n");
                    printf("** Generate the bill for each customer for the past month. Consider creating several types of bills.**\n");
                    printf(" Which year? : \n");
                    string year;
                    cin >> year;
                    printf(" Which month? : \n");
                    string month;
                    cin >> month;

                    if (year == "0" || month == "0") {
                        cout << "\n Quit Type 5\n";
                        break;
                    }
                    string query5 = "select * from Bill where (select month(issued_date) = '";
                    query5 += month;
                    query5 += "') and (select year(issued_date) = '";
                    query5 += year;
                    query5 += "')";

                    cout << "\n -- query: " << query5 << "\n\n";

                    char ch_query5[256];
                    strcpy(ch_query5, query5.c_str());

                    int state5 = 0;
                    state5 = mysql_query(connection, ch_query5);
                    cout << " \n\n -------- A Simple Bill ------------ \n\n";
                    printf("%15s | %15s | %15s \n", "Bill_ID", "Customer_ID", "Amount");
                    if (state5 == 0)
                    {
                        sql_result = mysql_store_result(connection);
                        while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
                        {
                            //printf("%s | ", sql_row[0]);
                            printf("%15s | %15s | %15s \n", sql_row[0], sql_row[6], sql_row[5]);
                        }
                        mysql_free_result(sql_result);
                    }
                    printf("\n\n");

                    cout << " \n\n -------- A Bill listing charges by type of service ------------ \n\n";
                    printf("%15s | %15s | %15s \n", "Bill_ID", "Type", "Amount");
                    state5 = mysql_query(connection, ch_query5);
                    if (state5 == 0)
                    {
                        sql_result = mysql_store_result(connection);
                        while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
                        {
                            printf("%15s | %15s | %15s \n", sql_row[0], sql_row[3], sql_row[5]);
                            //printf("%s | ", sql_row[0]);
                        }
                        mysql_free_result(sql_result);
                    }
                    //printf("\n\n");

                    cout << " \n\n -------- An Itemize billing ------------ \n\n";
                    printf("%15s | %15s | %15s | %15s | %15s\n", "Bill_ID", "Customer_id", "Package_id", "Method", "Charge");
                    state5 = mysql_query(connection, ch_query5);
                    if (state5 == 0)
                    {
                        sql_result = mysql_store_result(connection);
                        while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
                        {
                            //printf("%s | ", sql_row[0]);
                            printf("%15s | %15s | %15s | %15s | %15s\n", sql_row[0], sql_row[6], sql_row[1], sql_row[2], sql_row[5]);
                        }
                        mysql_free_result(sql_result);
                    }
                    printf("\n\n");

                    continue;
                }
             }

            else if (type == 0) {
                FILE* input_fp2 = NULL;
                input_fp2 = fopen("20191164_2.txt", "r");
                if (input_fp2 != NULL) {
                    char strTemp[255];
                    while (!feof(input_fp2)) {
                        query = fgets(strTemp, sizeof(strTemp), input_fp2);
                        mysql_query(connection, query);
                    }
                    fclose(input_fp2);
                    cout << "drop scussed\n";
                }
                
                cout << "Quit Program\n";
                break;
                
            }

            else {
                cout << "input error\n";
            }


            //printf("----------------------------------\n");


            /*
            FILE* input_fp2 = fopen("20191164_2.txt", "r");
            if (input_fp2 != NULL) {
                char str22[2048];
                // char query;
                while (!feof(input_fp2)) {
                    query = fgets(str22, sizeof(str22), input_fp2);
                    mysql_query(connection, query22);
                }
                cout << "drop scussed\n";
            }

            else fprintf(stderr, "file open error");

            fclose(input_fp2);
            break;
            */
            
            /*

            const char* query = "select * from student";
            int state = 0;

            state = mysql_query(connection, query);
            if (state == 0)
            {
                sql_result = mysql_store_result(connection);
                while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
                {
                    printf("%s %s %s %s\n", sql_row[0], sql_row[1], sql_row[2], sql_row[3]);
                }
                mysql_free_result(sql_result);
            }
             */

            mysql_close(connection);

            
        }
 
    }
    
    
	return 0;
}





/*

	printf("------- SELECT QUERY TYPES -------\n\n");
	printf("\t1. TYPE 1\n");
	printf("\t2. TYPE 2\n");
	printf("\t3. TYPE 3\n");
	printf("\t4. TYPE 4\n");
	printf("\t5. TYPE 5\n");
	printf("\t6. TYPE 6\n");
	printf("\t7. TYPE 7\n");
	printf("\t0. QUIT\n");
	//printf("----------------------------------\n");
	printf("\n\n");
	printf("---- TYPE 5 ----\n\n");
	printf("** Find the top k brands by unit sales by the year**\n");
	printf(" Which K? : 3\n");

	return 0;

}
*/
