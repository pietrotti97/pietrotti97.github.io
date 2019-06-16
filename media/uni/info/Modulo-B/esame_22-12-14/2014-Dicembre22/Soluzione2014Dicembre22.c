#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char termine[20];
}parola;

typedef struct tree_element{
	parola value;
	struct tree_element *left, *right;
}nodo;
typedef nodo *tree;

tree cons_tree(parola p,tree l,tree r){
	tree t;

	t=(nodo*)malloc(sizeof(nodo));
	t->value=p;
	t->left=l;
	t->right=r;

	return t;
}

tree insord(parola p,tree t){
	if(t==NULL) return cons_tree(p,NULL,NULL);
	else{
		if(strcmp(p.termine,t->value.termine)<0)
			t->left=insord(p,t->left);
		else t->right=insord(p,t->right);

		return t;
	}
}

tree funzioneA(FILE *fp,tree t){
	parola p;
	int i = 0;

	while(!feof(fp)){
		fscanf(fp,"%s",p.termine);
		if((p.termine[i]=='a' )||(p.termine[i]=='e') || (p.termine[i]=='i') || (p.termine[i]=='o') || (p.termine[i]=='u'))
			t=insord(p,t);
	}

	rewind(fp);
	return t;

}

void inorder(tree t){
	if(t!=NULL){
		inorder(t->left);
		printf("%s\n",t->value.termine);
		inorder(t->right);
	}
}

void funzioneB(tree t,FILE *fp){
	if(t!=NULL){
		funzioneB(t->left,fp);
		fprintf(fp,"%s\n",t->value.termine);
		funzioneB(t->right,fp);
	}

}

void funzioneC(parola V[],FILE *fp,int *i){
	parola p;
	int j=0;
	while(!feof(fp) && (*i)<100){
		fscanf(fp,"%s",p.termine);
		if((p.termine[j]=='a' )||(p.termine[j]=='e') || (p.termine[j]=='i') || (p.termine[j]=='o') || (p.termine[j]=='u')){
			strcpy(V[*i].termine,p.termine);
			(*i)++;
		}
	}

}

int fcmp(const void *a,const void *b){
	parola e,f;

	e=*(parola*)a;
	f=*(parola*)b;

	if(strcmp(e.termine,f.termine)<0) return -1;
	else{
		if(strcmp(e.termine,f.termine)>0) return 1;
		else return 0;
	}
}

main(){
	FILE *fp,*fp1,*fp2;
	parola V[100];
	int i=0;
	int k;
	tree t=NULL;

	fp=fopen("parole1.txt","rt");
	if(fp==NULL){
		printf("Errore apertura file parole1\n");
		exit(-1);
	}

	t=funzioneA(fp,t);

	inorder(t);

	fp1=fopen("uscita.txt","wt");
	if(fp1==NULL){
		printf("Errore apertura file output\n");
		exit(-1);
	}

	funzioneB(t,fp1);

	fclose(fp1);

	funzioneC(V,fp,&i);

	fclose(fp);

	qsort(V,i,sizeof(parola),fcmp);

	fp2=fopen("outputAB.txt","wt");
	if(fp2==NULL){
		printf("Errore apertura file outputAB\n");
		exit(-1);
	}

	for(k=0;k<i;k++){
		fprintf(fp2,"%s\n",V[k].termine);
	}
	fclose(fp2);
	
}