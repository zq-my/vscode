 
# 医院病房监护系统
class Patient:
    def __init__(self, name, age, gender, illness):
        self.name = name
        self.age = age
        self.gender = gender
        self.illness = illness
        self.report = f"{name}({gender}, {age}岁)的病情报告：{illness}"
        self.medical_record = []

    def update_medical_record(self, record):
        self.medical_record.append(record)

    def abnormal_alarm(self):
        print("病症出现异常！请立即处理！")

patient1 = Patient("张三", 30, "男", "感冒")
patient1.update_medical_record("2021-01-01：发烧38℃，咳嗽，流鼻涕")
patient1.update_medical_record("2021-01-02：体温正常，咳嗽，流鼻涕")
patient1.abnormal_alarm()
print(patient1.report)
print(patient1.medical_record)

 
# 医院病房监护系统
class Nurse:
    def __init__(self, name, age, gender, level):
        self.name = name
        self.age = age
        self.gender = gender
        self.level = level
        self.patients = []

    def add_patient(self, patient):
        self.patients.append(patient)

    def remove_patient(self, patient):
        self.patients.remove(patient)

    def check_patients(self):
        for patient in self.patients:
            if "病情恶化" in patient.medical_record[-1]:
                patient.abnormal_alarm()

nurse1 = Nurse("李四", 25, "女", "高级护士")
nurse1.add_patient(patient1)
nurse1.check_patients()

 
# 医院病房监护系统
class Doctor:
    def __init__(self, name, age, gender, department):
        self.name = name
        self.age = age
        self.gender = gender
        self.department = department
        self.patients = []

    def add_patient(self, patient):
        self.patients.append(patient)

    def remove_patient(self, patient):
        self.patients.remove(patient)

    def check_patients(self):
        for patient in self.patients:
            if "病情恶化" in patient.medical_record[-1]:
                patient.abnormal_alarm()

doctor1 = Doctor("王五", 35, "男", "内科")
doctor1.add_patient(patient1)
doctor1.check_patients()

 
# 医院病房监护系统
class Hospital:
    def __init__(self, name, address, level):
        self.name = name
        self.address = address
        self.level = level
        self.patients = []
        self.nurses = []
        self.doctors = []

    def add_patient(self, patient):
        self.patients.append(patient)

    def remove_patient(self, patient):
        self.patients.remove(patient)

    def add_nurse(self, nurse):
        self.nurses.append(nurse)

    def remove_nurse(self, nurse):
        self.nurses.remove(nurse)

    def add_doctor(self, doctor):
        self.doctors.append(doctor)

    def remove_doctor(self, doctor):
        self.doctors.remove(doctor)

    def check_patients(self):
        for patient in self.patients:
            if "病情恶化" in patient.medical_record[-1]:
                patient.abnormal_alarm()

    def check_nurses(self):
        for nurse in self.nurses:
            if "病情恶化" in nurse.patients[-1].medical_record[-1]:
                nurse.patients[-1].abnormal_alarm()

    def check_doctors(self):
        for doctor in self.doctors:
            if "病情恶化" in doctor.patients[-1].medical_record[-1]:
                doctor.patients[-1].abnormal_alarm()

hospital1 = Hospital("XX医院", "XX市XX区XX路XX号", "三级甲等")
hospital1.add_patient(patient1)
hospital1.add_nurse(nurse1)
hospital1.add_doctor(doctor1)
hospital1.check_patients()
hospital1.check_nurses()
hospital1.check_doctors()

 
# 医院病房监护系统
class Equipment:
    def __init__(self, name, status):
        self.name = name
        self.status = status

    def update_status(self, status):
        self.status = status

class Bed(Equipment):
    def __init__(self, name, status, patient=None):
        super().__init__(name, status)
        self.patient = patient

    def add_patient(self, patient):
        self.patient = patient

    def remove_patient(self):
        self.patient = None

class Monitor(Equipment):
    def __init__(self, name, status, patient=None):
        super().__init__(name, status)
        self.patient = patient

    def add_patient(self, patient):
        self.patient = patient

    def remove_patient(self):
        self.patient = None

bed1 = Bed("床1", "空闲")
bed2 = Bed("床2", "空闲")
monitor1 = Monitor("监护仪1", "空闲")
monitor2 = Monitor("监护仪2", "空闲")

patient2 = Patient("李四", 40, "女", "心脏病")
patient2.update_medical_record("2021-01-01：心慌，气短")
patient2.update_medical_record("2021-01-02：心慌，气短，胸痛")
patient2.update_medical_record("2021-01-03：心慌，气短，胸痛，心率过快")
patient2.update_medical_record("2021-01-04：心慌，气短，胸痛，心率过快，血压升高")
bed1.add_patient(patient2)
monitor1.add_patient(patient2)

nurse2 = Nurse("赵六", 30, "男", "高级护士")
nurse2.add_patient(patient2)
doctor2 = Doctor("钱七", 45, "女", "心血管内科")
doctor2.add_patient(patient2)

hospital1.add_patient(patient2)
hospital1.add_nurse(nurse2)
hospital1.add_doctor(doctor2)

print(patient2.report)
print(patient2.medical_record)
print(bed1.patient.report)
print(monitor1.patient.report)

# 医院病房监护系统
class Surgery:
    def __init__(self, name, date, patient, doctor, nurse, bed, monitor):
        self.name = name
        self.date = date
        self.patient = patient
        self.doctor = doctor
        self.nurse = nurse
        self.bed = bed
        self.monitor = monitor

    def perform_surgery(self):
        print(f"{self.patient.name}的{self.name}手术已完成！")

surgery1 = Surgery("心脏搭桥手术", "2021-01-05", patient2, doctor2, nurse2, bed1, monitor1)
surgery1.perform_surgery()

bed1.remove_patient()
monitor1.remove_patient()
hospital1.remove_patient(patient2)
hospital1.remove_nurse(nurse2)
hospital1.remove_doctor(doctor2)