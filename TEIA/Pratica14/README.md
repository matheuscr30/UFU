## Usage

For running this code, there are 3 arguments to be passed:
* --path or -p : Pass the path of the input file
* --hasheaders or -hh (default: 0) : Pass 0/1 if the input file has headers or not
* --class_idx -c: Pass the index of column that contains the class attribute (starting from 0)

## Examples

### Input file with no headers
```bash
python evaluateKMeans.py --path ./iris.data --class_idx 5
```
or
```bash
python evaluateKMeans.py --path ./iris.data --hasheaders 0 --class_idx 4
```

### Input file with headers
```bash
python evaluateKMeans.py --path ./iris.data --hasheaders 1 -c 0
```
