
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getGradePoint(int score);

int main() {

	char studentNames[3][20];
	char studentMatricNo[3][20];
	//First semeter course
	int Mit801[3];
	int Mit802[3];
	int Mit803[3];
	int Mit805[3];
	int Mit821[3];

	//second semeter course Array
	int Mit811[3];
	int Mit812[3];
	int Mit813[3];
	int Mit815[3];
	int Mit822[3];
	int totalPoint[3];
	float gpa[3];
	float cgpa[3];

	char name[20];
	char matricNo[20];
	//first semester
	int mit801;
	int mit802;
	int mit803;
	int mit805;
	int mit821;

	//second semeter course
	int mit811;
	int mit812;
	int mit813;
	int mit815;
	int mit822;

	char ch;

	int courseUnit = 3;
	int totalCourseUnit = 30;
	int i = 0;


	setbuf(stdout,NULL);

	printf("Starting.......\n");
	//Start
	//read from file
	FILE *studentRecord = fopen("StudentRecord.txt","r");

	if(studentRecord == NULL){
		printf("Ooop, StudentRecord.txt NOT FOUND");
		return EXIT_SUCCESS;
	}


	while(fscanf(studentRecord,"%20s %20s %3d %3d %3d %3d %3d %3d %3d %3d %3d %3d ",name,matricNo,&mit801,&mit802,&mit803,&mit805,&mit821,&mit811,&mit812,&mit813,&mit815,&mit822) != EOF){


		strcpy(studentNames[i],name);
		strcpy(studentMatricNo[i],matricNo);
		Mit801[i] = mit801;
		Mit802[i] = mit802;
		Mit803[i] = mit803;
		Mit805[i] = mit805;
		Mit821[i] = mit821;

		Mit811[i] = mit811;
		Mit812[i] = mit812;
		Mit813[i] = mit813;
		Mit815[i] = mit815;
		Mit822[i] = mit822;

		totalPoint[i] = ( (getGradePoint(mit801) * courseUnit) +
                   (getGradePoint(mit802) * courseUnit) +
				(getGradePoint(mit803) * courseUnit) +
                   (getGradePoint(mit805) * courseUnit)
				+ (getGradePoint(mit821) * courseUnit) +
                   (getGradePoint(mit811) * courseUnit) +
                   (getGradePoint(mit812) * courseUnit) +
				(getGradePoint(mit813) * courseUnit) +
                   (getGradePoint(mit815) * courseUnit)
				+ (getGradePoint(mit822) * courseUnit));
		 gpa[i] = (totalPoint[i] / totalCourseUnit);
		 cgpa[i] = (totalPoint[i] / totalCourseUnit);
		 i++;


	}

	fclose(studentRecord);

	FILE *StudentCalculatedRecord = fopen("StudentCalculatedRecord.txt","w+");

	fprintf(StudentCalculatedRecord,"S/N \tNAME \tMATRIC. NO. \tMIT801 \tMIT802 \tMIT803 \tMIT805 \tMIT821 \tMIT811 \tMIT812 \tMIT813 \tMIT815 \tMIT822 \tTOTALPOINT \tGPA \tCGPA \n");

	int j;
	for(j = 0; j < 3; j++){

		fprintf(StudentCalculatedRecord,"%d \t%s \t%s \t%3d \t%3d \t%3d \t%3d \t%3d \t%3d \t%3d \t%3d \t%3d \t%3d \t%3d \t\t%.2f \t%.2f\n",
				j+1, studentNames[j],studentMatricNo[j],Mit801[j],Mit802[j],Mit803[j],Mit805[j],Mit821[j],
				Mit811[j],Mit812[j],Mit813[j],Mit815[j],Mit822[j],totalPoint[j],gpa[j],cgpa[j]);

	}

	fclose(StudentCalculatedRecord);


	FILE *studentSecondResult2 = fopen("StudentCalculatedRecord.txt","r");

	while((ch = fgetc(studentSecondResult2)) != EOF){
		printf("%c",ch);
	}

	fclose(studentSecondResult2);

	return EXIT_SUCCESS;
}

int getGradePoint(int score){

	if(score >= 70){
		return 5;
	}

	if (score >=60 && score <70){

		return 4;
	}

	 if (score >=50 && score <60){

			return 3;
		}

	 if (score >=45 && score <50){

			return 2;
		}

	 if (score >=39 && score <45){

			return 1;
		}

	 if (score < 39){

			return 0;
		}
	 return 0;
}

