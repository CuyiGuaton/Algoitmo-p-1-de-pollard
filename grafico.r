    library(ggplot2)   
    options(scipen = 999)
    tabla=read.table("informe/table.txt", header = TRUE)
    num = tabla$V1    
    B=tabla$V2
    Tiempo=tabla$V3
    ggplot(data = tabla, aes(x=B, y=Tiempo)) +  geom_line()  + ggtitle("Tiempo vs B") + theme(plot.title = element_text(hjust = 0.5))
    
    ggplot(data = tabla, aes(x=num, y=Tiempo)) +  geom_line()  + ggtitle("Tiempo vs num") + theme(plot.title = element_text(hjust = 0.5))

    