# preparando o ambiente
import pandas as pd
import matplotlib.pyplot as plt
from collections import Counter

# Criando o dataframe da base de dados
caminho_arquivo=r'dados.xlsx'
df=pd.read_excel(caminho_arquivo)

#Ex1-a
# grafico de pizza - tipo_cobranca
print("Gráfico de pizza")
dados_pizza=Counter(df['tipo_cobranca'])
labels=list(dados_pizza.keys())
sizes=list(dados_pizza.values())
colors = ["red", "blue", "green", "orange"]
plt.pie(sizes,labels=labels,colors=colors,autopct="%1.1f%%")
plt.title("Preferência por Tipo de Cobrança")
plt.legend(labels, loc="upper right")
plt.show()

#Ex1-b
# grafico de barras - vezes_semana
print("Gráfico de barras")
dados_barra=Counter(df["vezes_semana"])
labels=list(dados_barra.keys())
values=list(dados_barra.values())
plt.bar(labels,values,color="skyblue",label="Frequência")
plt.title("Frequência de Recargas Semanais")
plt.xlabel("Quantidade de Recargas")
plt.ylabel("Quantidade de Pessoas")
plt.legend()
plt.show()

#Ex1-c
# histograma - energia_kwh
print("Histograma")
plt.hist(df["energia_kwh"],bins=5,color="green")
plt.title("Distribuição do Consumo de Energia")
plt.xlabel("Energia Consumida (kWh)")
plt.ylabel("Frequência")
plt.show()

#Ex1-d
# boxplot - tempo_recarga
print("Boxplot")
mapa_tempo={
    "30 min": 30,
    "30 a 60 min": 60,
    "60 a 120 min": 120,
    "120 ou mais": 150
}
df["tempo_recarga_num"]=df["tempo_recarga"].map(mapa_tempo)
plt.boxplot(df["tempo_recarga_num"],patch_artist=True,boxprops=dict(facecolor="orange"))
plt.title("Boxplot do Tempo de Recarga")
plt.xlabel("Fonte da Pesquisa")
plt.ylabel("Tempo em Minutos")
plt.show()

# Ex2-analise1-energia_kwh
print("Análise 1")
print("Energia kwh")
# a- 
print(f"Média: {df['energia_kwh'].mean()}")
print(f"Mediana: {df['energia_kwh'].median()}")
print(f"Moda:{df['energia_kwh'].mode()}")
# b- 
print(f"Máximo: {df['energia_kwh'].max()}")
print(f"Mínimo: {df['energia_kwh'].min()}")
amplitude=df["energia_kwh"].max()-df["energia_kwh"].min()
print(f"Amplitude: {amplitude}")
print(f"Variância: {df['energia_kwh'].var()}")
print(f"Desvio Padrão: {df['energia_kwh'].std()}")
cv = (df["energia_kwh"].std()/df["energia_kwh"].mean())*100
print(f"Coeficiente de Variação: {cv}")
# c-
print(df["energia_kwh"].quantile([0.25, 0.50, 0.75]))

# Ex2-analise2-vezes_semana
print("Analise 2")
print("vezes semana")
# a-
print(f"Média: {df['vezes_semana'].mean()}")
print(f"Mediana: {df['vezes_semana'].median()}")
print(f"Moda:\n{df['vezes_semana'].mode()}")
# b-
print(f"Máximo: {df['vezes_semana'].max()}")
print(f"Mínimo: {df['vezes_semana'].min()}")
amplitude=df["vezes_semana"].max()-df["vezes_semana"].min()
print(f"Amplitude: {amplitude}")
print(f"Variância: {df['vezes_semana'].var()}")
print(f"Desvio Padrão: {df['vezes_semana'].std()}")
cv=(df["vezes_semana"].std()/df["vezes_semana"].mean())*100
print(f"Coeficiente de Variação: {cv}%")
# c-
print(df["vezes_semana"].quantile([0.25, 0.50, 0.75]))