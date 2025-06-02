#pragma once

/// <summary>
/// ��������� ��������� ���� ��� ������ � ���������������� �������.
/// </summary>
/// <typeparam name="T">��� ������, ������� ����� ��������� � ����.</typeparam>
template <typename T>
struct Node
{
    T data;
    Node* next;

    /// <summary>
    /// ����������� ����, ��������� ������ � ��������� �� ��������� ����.
    /// </summary>
    Node(T value, Node* nextNode = nullptr)
        : data(value), next(nextNode)
    {
    }
};