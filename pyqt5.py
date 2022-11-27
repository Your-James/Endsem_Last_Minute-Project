from PyQt5 import QtWidgets
from PyQt5.QtWidgets import QApplication, QMainWindow
import sys

def window():
    app = QApplication(sys.argv)
    win = QMainWindow()
    win.setGeometry(200, 200, 300, 300)
    win.setWindowTitle('Python Project')

    label = QtWidgets.QLabel(win)
    label.setText("First Label!\nAman Jain\nVIIT")
    label.move(150, 50)


    win.show()
    sys.exit(app.exec_())


window()


 