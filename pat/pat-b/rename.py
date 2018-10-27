import os
os.chdir('/Users/k/Documents/prac_code/pat-b/')
for file_name in os.listdir('.'):
    if(file_name[:4] == 'patb'):
        new_file_name = file_name[5:]
        cmd = 'mv %s %s' %(file_name,new_file_name)
        # print(cmd)
        os.system(cmd)
        






