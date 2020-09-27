
from PIL import Image
import PIL


from pdf2image import convert_from_path, convert_from_bytes

# images = convert_from_path('./test.pdf')

images_from_path = convert_from_path('./test.pdf', size=(9999, None))


images_from_path[0].save('./test.jpg')