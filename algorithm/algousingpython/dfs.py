import numpy as np

ar=np.zeros((4,4),dtype=int)
flg=np.zeros((4),dtype=int)
ar[0,3]=ar[3,0]=ar[2,3]=ar[3,2]=ar[1,3]=ar[3,1]=ar[1,2]=ar[2,1]=1

print ar

def dfs(i,n):
	for j in range(n):
		if(ar[i,j]!=0):
			dfs2(j,n)
		
def dfs2(i,n):
	for m in range(n):
		if(flg[m]!=1 and ar[i,m]==1):
			print m
			flg[m]=1
			dfs2(m,n)

dfs(0,4)

		
