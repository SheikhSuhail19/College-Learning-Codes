# Grab all files that have json as extension
json_list = list(Path('C:\\Users\\sheik\\Downloads\\4th Sem\\Subjects\\TAFL\\TAFL Neso Academy').rglob('*.json'))
# Split on the first occurance of the dash
index = [x.name.split("-",1)[0] for x in json_list]
# Split again on the dot
names = [x.name.split("-",1)[1].split(".",1)[0] for x in json_list]

folder_p = Path(folder_path)

# zipping puts the two lists side by side
# and iteratively goes through both of them
# one by one
for i,name in zip(index,names):
    # combine the folder name with the id
    p = folder_p / i

    # rename file with new name and new suffix
    p.rename((p.parent / (i + "-" + name)).with_suffix('.mp4'))