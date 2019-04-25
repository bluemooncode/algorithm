import numpy as np

size=input('Enter the maximunm capacity')
n=input('Number of iteams')
iteams=[]
for i in range(n):
	j,k=input()
	iteams.append([j,k])
"""
for i in range(n):
	print iteams[i]

for i in range(1,n):
	j=i-1
	v=iteams[i]
	while(j>=0):
		if(iteams[j][0]>v[0]):
			iteams[j+1]=iteams[j]

		else:
			break
		j=j-1

	iteams[j+1]=v

for i in range(n):
	print iteams[i]
"""
arr=np.zeros((n+1,size+1),dtype=int)
for i in range(1,n+1):
	for j  in range(1,size+1):
		if(j>=iteams[i-1][0]):
			if(arr[i-1][j]>arr[i-1][j-iteams[i-1][0]]+iteams[i-1][1]):
				arr[i][j]=arr[i-1][j]
			else:
				arr[i][j]=arr[i-1][j-iteams[i-1][0]]+iteams[i-1][1]
		else:
			arr[i][j]=arr[i-1][j]

for i in range(n+1):
	print arr[i]


