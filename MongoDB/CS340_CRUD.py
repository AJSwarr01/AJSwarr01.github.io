from pymongo import MongoClient
from bson.objectid import ObjectId
from bson.json_util import dumps


class AnimalShelter(object):
    
    def __init__(self, username, password):
        self.client = MongoClient('mongodb://%s:%s@localhost:46578' % (username, password))
        self.database = self.client['AAC']
                

# Create method to implement the C in CRUD.
    def create(self, data):
        if data != None:
            self.database.animals.insert(data) 
            print('Data has been inserted')
        else:
            raise Exception('Nothing to save, because data parameter is empty')

# Create method to implement the R in CRUD. 
    def read(self, data):
        if data != None:
            print('Data found!')
            cursor = self.database.animals.find(data)
            return(dumps(cursor))            
        else:
            raise Exception('Nothing to find, because data parameter is empty')
            
# Create method to implement the U in CRUD. 
    def update(self, query, data):
        if data != None:
            self.database.animals.update_one(query, data)
            print('Data updated!')                        
        else:
            raise Exception('Nothing to update, because data parameter is empty')

 # Create method to implement the D in CRUD. 
    def delete(self, data):
        if data != None:
            self.database.animals.remove(data)
            print('Data removed!')
        else:
            raise Exception('Nothing to remove, because data parameter is empty')