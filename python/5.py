import datetime

# 定义航班类
class Flight:
    def __init__(self, flight_number, origin, destination, departure_time, arrival_time, price):
        self.flight_number = flight_number
        self.origin = origin
        self.destination = destination
        self.departure_time = departure_time
        self.arrival_time = arrival_time
        self.price = price

# 定义航空公司类
class Airline:
    def __init__(self, name, flights):
        self.name = name
        self.flights = flights

    # 显示所有航班信息
    def display_flights(self):
        print("航班信息：")
        for flight in self.flights:
            print(f"航班号：{flight.flight_number}，出发地：{flight.origin}，目的地：{flight.destination}，出发时间：{flight.departure_time}，到达时间：{flight.arrival_time}，价格：{flight.price}")

# 定义订票系统类
class BookingSystem:
    def __init__(self, airlines):
        self.airlines = airlines

    # 显示所有航空公司信息
    def display_airlines(self):
        print("航空公司信息：")
        for airline in self.airlines:
            print(f"航空公司：{airline.name}")

    # 显示某个航空公司的所有航班信息
    def display_flights_by_airline(self, airline_name):
        for airline in self.airlines:
            if airline.name == airline_name:
                airline.display_flights()

    # 根据航班号查询航班信息
    def search_flight_by_number(self, flight_number):
        for airline in self.airlines:
            for flight in airline.flights:
                if flight.flight_number == flight_number:
                    return flight
        return None

    # 订票
    def book_flight(self, flight_number):
        flight = self.search_flight_by_number(flight_number)
        if flight is None:
            print("航班不存在")
            return
        print(f"您已成功订购航班号为{flight.flight_number}的航班，价格为{flight.price}元")

# 创建航班
flight1 = Flight("MU1234", "上海", "北京", datetime.datetime(2022, 1, 1, 8, 0), datetime.datetime(2022, 1, 1, 10, 30), 1000)
flight2 = Flight("MU2345", "北京", "上海", datetime.datetime(2022, 1, 1, 14, 0), datetime.datetime(2022, 1, 1, 16, 30), 1200)
flight3 = Flight("CZ3456", "上海", "广州", datetime.datetime(2022, 1, 1, 10, 0), datetime.datetime(2022, 1, 1, 12, 30), 800)
flight4 = Flight("CZ4567", "广州", "上海", datetime.datetime(2022, 1, 1, 16, 0), datetime.datetime(2022, 1, 1, 18, 30), 900)

# 创建航空公司
airline1 = Airline("东方航空", [flight1, flight2])
airline2 = Airline("南方航空", [flight3, flight4])

# 创建订票系统
booking_system = BookingSystem([airline1, airline2])

# 显示所有航空公司信息
booking_system.display_airlines()

# 显示某个航空公司的所有航班信息
booking_system.display_flights_by_airline("南方航空")

# 根据航班号查询航班信息
flight = booking_system.search_flight_by_number("CZ3456")
if flight is not None:
    print(f"航班号为{flight.flight_number}的航班价格为{flight.price}元")

# 订票
booking_system.book_flight("CZ3456")