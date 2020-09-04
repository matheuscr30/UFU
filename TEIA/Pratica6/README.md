## Usage

For running this code, there are 2 arguments to be passed:
* --path or -p : Pass the path of the input file
* --hasheaders or -hh (optional) : Pass 0/1 if the input file has headers or not
* --clusters -c: Pass the number of clusters for the execution of k-means

## Examples

### Input file with no headers
```bash
python calculateKMeans.py --path ./input-file.csv --clusters 5
```
or
```bash
python calculateKMeans.py --path ./input-file.csv --hasheaders 0 --clusters 4
```

### Input file with headers
```bash
python calculateKMeans.py --path ./input-file.csv --hasheaders 1 -c 10
```
