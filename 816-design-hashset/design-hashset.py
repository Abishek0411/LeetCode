class MyHashSet(object):

    def __init__(self):
        self.hashset = []

    def add(self, key):
        if not self.contains(key):
            self.hashset.append(key)
        

    def remove(self, key):
        if self.contains(key):
            self.hashset.remove(key)
        

    def contains(self, key):
        if key in self.hashset:
            return True
        


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)