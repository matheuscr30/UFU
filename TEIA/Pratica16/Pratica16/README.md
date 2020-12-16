## Usage

For running this code, there are 3 arguments to be passed:
* --path or -p : Pass the path of the input file
* --hasheaders or -hh (default: 0) : Pass 0/1 if the input file has headers or not
* --hasclass or -hc (default: 0) : Pass 0/1 if the input has a class attribute
* --class_idx -c (optional): Pass the index of column that contains the class attribute (starting from 0)

## Examples

### Input file with no headers without class attribute
```bash
python evaluateKMeans.py --path ./iris.data
```
or
```bash
python evaluateKMeans.py --path ./iris.data --hasheaders 0 --hasclass 0
```

### Input file with no headers with class attribute
```bash
python evaluateKMeans.py --path ./iris.data --hasclass 1 --class_idx 4
```
or
```bash
python evaluateKMeans.py --path ./iris.data --hasheaders 0 -hc 1 -c 4
```

### Input file with headers without class attribute
```bash
python evaluateKMeans.py --path ./iris.data --hasheaders 1
```

### Input file with headers with class attribute
```bash
python evaluateKMeans.py --path ./iris.data -hh 1 --hasclass 1 -c 4
```
