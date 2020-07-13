{
    tPedi a, b;
    tPila pA, pB;
	double total;
	size_t fin, 
		   precioCero = 0;

    crearPila_MIO(&pA);
    crearPila_MIO(&pB);

    fin = !fread(&a, sizeof(tPedi),1, fpPedi);

    while(!fin)
    {
        if(verTope_MIO(&pA,&b,sizeof(tPedi)) && !strcmp(a.codClie, b.codClie))
        {
            if(!ponerEnPila_MIO(&pA, &a, sizeof(tPedi)))
                fprintf(stderr,"ERROR - inesperado - pila llena\n");
        }
        else
        {
            /**/
            while(sacarDePila_MIO(&pA, &b, sizeof(tPedi)))
            {
                if(!ponerEnPila_MIO(&pB, &b, sizeof(tPedi)))
                    fprintf(stderr,"ERROR - inesperado - pila llena\n");

                if(!b.precUnit)
                    precioCero = 1;

                total+=b.precUnit*b.cant;
            }

			
            if(!precioCero && total>MAYOR_QUE)
            {
                fprintf(fpMayo, "Pedido del cliente %s por %.2f\n\n"
                                "CodProduc. Cant.  PrecUnit  SubTotal\n",
                                b.codClie, total);
            }
            if(!precioCero && total>=1 && total<=MAYOR_QUE)
            {
                fprintf(fpMeno, "Pedido del cliente %s por %.2f\n\n"
                                "CodProduc. Cant.  PrecUnit  SubTotal\n",
                                b.codClie, total);
            }

            while(sacarDePila_MIO(&pB, &b, sizeof(tPedi)))
            {

                if(precioCero)
                    fwrite(&b,sizeof(tPedi),1, fpPend);
                else
                {
                    if(total>MAYOR_QUE)
                        fprintf(fpMayo, "%-*s%*d %*.2f %*.2f\n", sizeof("CodProduc."),b.codProd,
                                                                 sizeof("Cant"),b.cant,
                                                                 sizeof("PrecUnit"),b.precUnit,
                                                                 sizeof("SubTotal"),b.precUnit*b.cant);
                    if(total >= 1 && total<=MAYOR_QUE)
                        fprintf(fpMeno, "%-*s%*d %*.2f %*.2f\n", sizeof("CodProduc."),b.codProd,
                                                                 sizeof("Cant"),b.cant,
                                                                 sizeof("PrecUnit"),b.precUnit,
                                                                 sizeof("SubTotal"),b.precUnit*b.cant);
                }

            }
			if(!precioCero)
			{
				if(total>MAYOR_QUE)
					fprintf(fpMayo,"\n\n\n");
				if(total>=1 && total<=MAYOR_QUE)
					fprintf(fpMeno,"\n\n\n");
			}
            precioCero = 0;
            total = 0;

            if(!ponerEnPila_MIO(&pA, &a, sizeof(tPedi)))
                fprintf(stderr,"ERROR - inesperado - pila llena\n");
        }


        if(!fread(&a, sizeof(tPedi),1, fpPedi) && feof(fpPedi))
        {
            if(verTope_MIO(&pA,&b,sizeof(tPedi)) && !strcmp(b.codClie, "\0"))
                fin=1;
            else
                strcpy(a.codClie, "\0");
        }

    }
}

