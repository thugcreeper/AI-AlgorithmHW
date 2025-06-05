
Partial Class _Default
    Inherits System.Web.UI.Page
    Function fibo(ByVal num As Integer) As Integer
        Dim i, sum As Integer
        Dim arr(num - 1) As Integer 'array
        arr(0) = 1
        arr(1) = 1
        sum = 2
        If num = 0 Then
            sum = 1
        Else
            Label1.Text &= "1+1+"
            For i = 2 To num - 1
                arr(i) = arr(i - 1) + arr(i - 2)
                sum += arr(i)
                Label1.Text &= arr(i)
                If i < num Then
                    Label1.Text &= "+"
                End If
            Next
        End If
        Label1.Text &= "=" & sum
        Return sum
    End Function
    Protected Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Dim num, sum As Integer
        num = CInt(TextBox1.Text)
        sum = fibo(num)
        'Label1.Text = sum & "<br>"
    End Sub
End Class
