import numpy as np

class node:
	def __init__(self,data):
		self.left=None
		self.right=None
		self.data=data
	def __str__(self):
		return (str(self.data))
def disp(root):
	if(root==None):
		return
	print root
	disp(root.left)
	
	disp(root.right)
	return


def dfs(v,temp):
	for i in range(n):
		if(flg[i]!=1):
			dfs2(i,temp)

def dfs2(w,temp):
	flg[w]=1
	temp.left=node(w)
	temp=temp.left
	for i in range(n):
		if(ar[w,i]==1 and flg[i]!=1):
			dfs2(i,temp)

root=node("Root")

ar=np.zeros((4,4),dtype=int)
flg=np.zeros(4,dtype=int)
n=4 
ar[0,1]=ar[1,0]=ar[1,2]=ar[2,1]=ar[0,3]=ar[3,0]=ar[1,3]=ar[3,1]=ar[2,3]=ar[3,2]=1



dfs(0,root)
disp(root)



