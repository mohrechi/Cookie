import json
import sys
from collections import OrderedDict
class MapReduce:
    def __init__(self):
        self.intermediate = OrderedDict()
        self.result = []

    def emitIntermediate(self, key, value):
        self.intermediate.setdefault(key, [])
        self.intermediate[key].append(value)

    def emit(self, value):
        self.result.append(value) 

    def execute(self, data, mapper, reducer):
        for line in data:
            record = json.loads(line)
            mapper(record)

        for key in self.intermediate:
            reducer(key, self.intermediate[key])

        jenc = json.JSONEncoder()
        for item in self.result:
            print "{\"key\":\""+item[0]+"\",\"value\":" + str(item[1]) + "}"

mapReducer = MapReduce()

def mapper(record):
    key = record["key"]
    value = record["value"]
    words = value.split()
    for w in words:    
      mapReducer.emitIntermediate(w, (w, 1))

def reducer(key, list_of_values): 
    total = sum([list_of_values[i][1] for i in range(len(list_of_values))])
    mapReducer.emit((key, total))


if __name__ == '__main__':
  inputData = []
  counter = 0
  for line in sys.stdin:
   counter += 1
   inputData.append(json.dumps({"key":counter,"value":line}))
  mapReducer.execute(inputData, mapper, reducer)
