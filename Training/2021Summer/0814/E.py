import random
import pickle
import numpy as np


class way():
    def __init__(self):
        self.data = []
        self.is_AI = 0

    def feed(self, pair):
        self.data.append(pair)

    def clear(self):
        self.data = []


class rand(way):
    def get_result(self):
        return random.randint(1, 3)


class offset_rand(way):
    def get_result(self):
        x = random.randint(1, 100)
        if x <= 30:
            return 1
        if x <= 80:
            return 2
        return 3


class circle(way):
    def __init__(self, circle):
        way.__init__(self)
        self.count = 0
        self.circle = circle
        self.t = len(circle)

    def get_result(self):
        self.count = (self.count+1) % self.t
        return self.circle[self.count]

    def clear(self):
        self.count = 0


class copy(way):
    def get_result(self):
        if len(self.data) == 0:
            return random.randint(1, 3)
        return self.data[-1][1]


class mle(way):
    def __init__(self):
        way.__init__(self)
        self.count = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
        self.pair_keep = (0, 0)

    def clear(self):
        self.count = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
        self.pair_keep = (0, 0)

    def feed(self, pair):
        self.count[self.pair_keep[1]-1][pair[1]-1] += 1
        self.pair_keep = pair

    def get_result(self):
        if self.pair_keep == (0, 0):
            return random.randint(1, 3)
        return (np.argmax(self.count[self.pair_keep[1]-1])+1) % 3+1

    def show_matrix(self):
        print('The Matrix is:')
        print(self.count)


class most(way):
    def __init__(self):
        way.__init__(self)
        self.count = [0, 0, 0]

    def clear(self):
        self.count = [0, 0, 0]

    def feed(self, pair):
        self.count[pair[1]-1] += 1

    def get_result(self):
        if self.count == [0, 0, 0]:
            return random.randint(1, 3)
        return (np.argmax(self.count)+1) % 3+1


class faded_AI(way):
    def __init__(self, dim):
        self.is_AI = 1
        self.dim = dim
        self.learning = 1
        self.dic = {}
        self.pairs_keep = []
        self.learning_rate = 1
        self.constant_mistakes = 0
        self.last_x = []
        for i in range(self.dim):
            self.pairs_keep.append([])
        self.count = 0
        self.w = []
        for i in range(3):
            self.w.append(np.zeros(dim+1))

    def clear(self):
        self.dic = {}
        self.pairs_keep = []
        self.learning_rate = 1
        self.constant_mistakes = 0
        for i in range(self.dim):
            self.pairs_keep.append([])
        self.count = 0
        self.w = []
        for i in range(3):
            self.w.append(np.zeros(self.dim+1))

    def load(self, filename):
        f = open(filename, 'rb')
        (self.count, self.dim, self.learning_rate, self.constant_mistakes,
         self.w, self.last_x, self.pairs_keep, self.dic) = pickle.load(f)

    def save(self, filename):
        f = open(filename, 'wb')
        pickle.dump((self.count, self.dim, self.learning_rate, self.constant_mistakes,
                    self.w, self.last_x, self.pairs_keep, self.dic), f)

    def feed(self, pair):
        self.count += 1
        for i in range(self.dim):
            if len(self.pairs_keep[i]) == i+1:
                if tuple(self.pairs_keep[i]) not in self.dic:
                    self.dic[tuple(self.pairs_keep[i])] = [0, 0, 0]
                self.dic[tuple(self.pairs_keep[i])][pair[1]-1] += 1
                del self.pairs_keep[i][0]
            self.pairs_keep[i].append(pair)
        if self.learning == 1:
            if pair[1] == pair[0] % 3+1:
                self.w[(pair[1]-1) % 3] += self.learning_rate * \
                    1*self.last_x[(pair[1]-1) % 3]
                self.w[(pair[0]+1) % 3] -= self.learning_rate * \
                    1*self.last_x[(pair[0]+1) % 3]
                self.constant_mistakes += 1
                if self.learning_rate*pow(1.1, self.constant_mistakes) > 1:
                    self.learning_rate = 1
                else:
                    self.learning_rate *= pow(1.1, self.constant_mistakes+1)
                self.learning_rate = 1
            elif pair[1] == pair[0]:
                self.w[(pair[1]-1) % 3] += self.learning_rate * \
                    0.5*self.last_x[(pair[1]-1) % 3]
                self.w[(pair[0]+1) % 3] -= self.learning_rate * \
                    0.5*self.last_x[(pair[0]+1) % 3]
            else:
                self.constant_mistakes = 0
                self.learning_rate /= 1.1

    def get_result(self):
        x = []
        for i in range(3):
            x.append(np.zeros(self.dim+1))
            #######
            x[i][self.dim] = 1
        for i in range(len(self.pairs_keep)):
            if self.count-i <= 0:
                break
            tup = tuple(self.pairs_keep[i])
            # print(self.dic)
            if tup not in self.dic:
                for j in range(3):
                    x[j][i] = 0
            else:
                sumi = 0
                for j in range(3):
                    sumi += self.dic[tup][j]
                for j in range(3):
                    x[j][i] = self.dic[tup][j]/sumi
        self.last_x = x
        result_lis = []
        for i in range(3):
            result_lis.append(np.dot(self.w[i], x[i]))
        # print(result_lis)
        return (random.choice(list(np.where(result_lis == np.max(result_lis))[0]))+1) % 3+1


def play(way):
    count = [0, 0, 0]
    print('type 1,2,3 as R,P and S')
    print('type 0 to show the current scorceboard,type -1 to end playing')
    while 1:
        while 1:
            try:
                i = int(input('You: '))
            except:
                continue
            if i >= -1 and i <= 3:
                break
        if i == 0 or i == -1:
            print('tie: '+str(count[0]))
            print('win: '+str(count[1]))
            print('los: '+str(count[2]))
            if i == -1:
                if count[1]+count[2] != 0:
                    print('win rate:'+str(count[1]/(count[1]+count[2])))
                break
            continue
        result = way.get_result()
        print('bot: '+str(result))
        way.feed((result, i))
        if i == result:
            print('tie')
            count[0] += 1
        elif (i-2) % 3+1 == result:
            print('win')
            count[1] += 1
        else:
            print('los')
            count[2] += 1


def bot_vs(way1, way2, n):
    count = [0, 0, 0]
    for i in range(n):
        result1 = way1.get_result()
        result2 = way2.get_result()
        #print('bot1: '+str(result1))
        #print('bot2: '+str(result2))
        way1.feed((result1, result2))
        way2.feed((result2, result1))
        if result1 == result2:
            # print('tie')
            count[0] += 1
        elif (result1-2) % 3+1 == result2:
            # print('win')
            count[1] += 1
        else:
            # print('los')
            count[2] += 1
    #print('tie: '+str(count[0]))
    #print('win: '+str(count[1]))
    #print('los: '+str(count[2]))
    #print('win rate:'+str(count[1]/(count[1]+count[2])))
    if count[1]+count[2] == 0:
        win_rate = 0
    else:
        win_rate = count[1]/(count[1]+count[2])
    print(str(way1.__class__.__name__)+' vs ' +
          str(way2.__class__.__name__)+' : '+str(win_rate))
    return win_rate > 0.5


def competition(way_list):
    count = []
    for i in range(len(way_list)):
        count.append(0)
    for i in range(len(way_list)):
        for j in range(i+1, len(way_list)):
            # adjustable
            if way_list[i].is_AI or way_list[j].is_AI:
                bot_vs(way_list[i], way_list[j], 100000)
            result = bot_vs(way_list[i], way_list[j], 10000)
            way_list[i].clear()
            way_list[j].clear()
            count[i] += result
            count[j] += 1-result
    print('wins count:')
    print(count)
    print('The strongest way is ' +
          str(way_list[np.argmax(count)].__class__.__name__))


if __name__ == "__main__":
    print('Welcome to RPS world.\nWhat do you want to do?')
    while 1:
        way_list = []
        # RAND=rand()
        COPY = copy()
        MOST = most()
        OFFSET_RAND = offset_rand()
        CIRCLE = circle([1, 2, 3, 3, 2, 1])
        MLE = mle()
        AI1 = faded_AI(4)
        # you can adjust the parameter (4) to decide how many steps are considered for AI to make a decision
        # way_list.append(RAND)
        way_list.append(COPY)
        way_list.append(MOST)
        way_list.append(OFFSET_RAND)
        way_list.append(CIRCLE)
        way_list.append(MLE)
        way_list.append(AI1)
        print('Type 1 to play against a bot/AI,2 to run a competition agains bots/AIs,-1 to quit:')
        try:
            choice = int(input())
        except:
            continue
        if choice == 1:
            print('Which one do you want to play with?')
            for i in range(len(way_list)):
                print(str(i)+':'+str(way_list[i].__class__.__name__))
            against_choice = -1
            while 1:
                try:
                    against_choice = int(input())
                except:
                    continue
                if against_choice in range(len(way_list)):
                    break
            against = way_list[against_choice]
            if against.is_AI == 1:
                print(against.__class__.__name__)
                against.learning = 1
                print(
                    'You are playing against a AI,would you like to load a trained model?(0/1 to choose)')
                while 1:
                    try:
                        YN1 = int(input())
                    except:
                        continue
                    if YN1 == 0:
                        break
                    if YN1 == 1:
                        print('Please type the filename of the model:')
                        fn = input()
                        load_success = 1
                        try:
                            against.load(fn)
                        except:
                            load_success = 0
                            print('load failed')
                        if load_success == 1:
                            print(
                                'would you like the model to learn from you?(0/1 to choose)')
                            while 1:
                                try:
                                    YN2 = int(input())
                                except:
                                    continue
                                if YN2 == 0:
                                    against.learning = 0
                                    break
                                if YN2 == 1:
                                    break
                    break
            play(against)
            if against.is_AI:
                if against.learning == 1:
                    print(
                        'Would you like save the model after training by you?(0/1 to choose)')
                    while 1:
                        try:
                            YN3 = int(input())
                        except:
                            continue
                        if YN3 == 0:
                            break
                        if YN3 == 1:
                            print(
                                'Please type the filename you want to save the model:')
                            fn2 = input()
                            try:
                                against.save(fn2)
                            except:
                                print('save failed')
                            break
            against.clear()
        if choice == 2:
            competition(way_list)
        if choice == -1:
            break
