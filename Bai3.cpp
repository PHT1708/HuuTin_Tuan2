from ._anvil_designer import HomeFormTemplate
from anvil import *
import anvil.server
import anvil.tables as tables
import anvil.tables.query as q
from anvil.tables import app_tables


class HomeForm(HomeFormTemplate):

  def __init__(self, **properties):

    self.init_components(**properties)


  def submit_button_1(self, **event_args):
    so = self.DaySo.text
    if so.strip() == "":
       self.Ketqua.text = "Vui lòng nhập dãy số"
    else:

       if self.InsertionSort.selected:
         sorted_numbers = insertion_sort(so.split())
         self.clear_inputs()
         self.Ketqua.text = "Dãy số sau khi sắp xếp bằng Insertion Sort: " + " ".join(sorted_numbers)
       elif self.SelectionSort.selected:
          sorted_numbers = selection_sort(so.split())
          self.clear_inputs()
          self.Ketqua.text = "Dãy số sau khi sắp xếp bằng Selection Sort: " + " ".join(sorted_numbers)
       elif self.BubbleSort.selected:
          sorted_numbers = bubble_sort(so.split())
          self.clear_inputs()
          self.Ketqua.text = "Dãy số sau khi sắp xếp bằng Bubble Sort: " + " ".join(sorted_numbers)
       elif self.MergeSort.selected:
          sorted_numbers = merge_sort(so.split())
          self.clear_inputs()
          self.Ketqua.text = "Dãy số sau khi sắp xếp bằng Merge Sort: " + " ".join(sorted_numbers)
         
          

  def clear_inputs(self):
    self.Ketqua.text = ""


def insertion_sort(arr):
    arr = list(map(int, arr))  # Chuyển các chuỗi thành số nguyên
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return list(map(str, arr))  # Chuyển các số nguyên thành chuỗi để hiển thị trên giao diện


def selection_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]
    return arr

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        swapped = False
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        if not swapped:
            break
    return arr

def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        L = arr[:mid]
        R = arr[mid:]

        merge_sort(L)
        merge_sort(R)

        i = j = k = 0

        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1

        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1

        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1

    return arr